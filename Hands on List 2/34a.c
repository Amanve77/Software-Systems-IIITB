/*
============================================================================
Name : 34a.c
Author : Aman Verma
Description :  Write a program to create a concurrent server.
                a. use fork
Date: 20th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


void handle_client(int client_socket, int client_counter) 
{
    char buffer[1024];
    int n;

    while ((n = read(client_socket, buffer, sizeof(buffer))) > 0) 
    {
        buffer[n] = '\0';
        printf("Client %d: %s\n", client_counter, buffer);
        write(client_socket, buffer, n);
    }

    close(client_socket);
    printf("Client disconnected %d\n", client_counter);
}

int main() 
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pid_t child_pid;
    int client_counter = 0;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) 
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) 
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) < 0) 
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", 8080);

    while (1) 
    {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        if (client_socket < 0) 
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        client_counter++;
        printf("Connected to Client %d\n", client_counter);

        if ((child_pid = fork()) == 0) 
        {
            close(server_socket);
            handle_client(client_socket, client_counter);
            exit(0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}


/*
============================================================================
Output:
    Server is listening on port 8080...
    Connected to Client 1
    Connected to Client 2
    Client 1: Hi

    Client 2: hello

    Client 1: How are you?

    Client 2: I am fine

    Client 1: ok bye

    Client 2: byeee

    Client disconnected 2
    Client disconnected 1
============================================================================
*/