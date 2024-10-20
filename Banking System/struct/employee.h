#ifndef EMPLOYEE
#define EMPLOYEE

struct employee {
    int employeeID;            // Unique employee ID
    char first_name[30];        // Employee's first name
    char last_name[30];         // Employee's last name
    char password[50];          // Employee's password (hashed or plain for now)
    char status[20];            // Employment status (e.g., "Active", "Inactive")
    int assigned_loans[10];     // IDs of loans assigned (max 10 at a time)
    int loan_count;             // Number of currently assigned loans
};


#endif