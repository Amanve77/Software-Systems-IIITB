/*
============================================================================
Name : 2.c
Author : Aman Verma
Description : Write a simple program to execute in an infinite loop at the background. 
			  Go to /proc directory and identify all the process related information in the corresponding proc directory
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() 
{
	for(;;)
			sleep(1);

	return 0;
}
/*
============================================================================
Output:
	Name:   q2
	Umask:  0002
	State:  S (sleeping)
	Tgid:   10904
	Ngid:   0
	Pid:    10904
	PPid:   8152
	TracerPid:      0
	Uid:    1000    1000    1000    1000
	Gid:    1000    1000    1000    1000
	FDSize: 256
	Groups: 4 24 27 30 46 100 118 1000 
	NStgid: 10904
	NSpid:  10904
	NSpgid: 10904
	NSsid:  8152
	VmPeak:     2556 kB
	VmSize:     2488 kB
	VmLck:         0 kB
	VmPin:         0 kB
	VmHWM:      1024 kB
	VmRSS:      1024 kB
	RssAnon:               0 kB
	RssFile:            1024 kB
	RssShmem:              0 kB
	VmData:       92 kB
	VmStk:       136 kB
	VmExe:         4 kB
	VmLib:      1672 kB
	VmPTE:        40 kB
	VmSwap:        0 kB
	HugetlbPages:          0 kB
	CoreDumping:    0
	THP_enabled:    1
	Threads:        1
	SigQ:   0/60986
	SigPnd: 0000000000000000
	ShdPnd: 0000000000000000
	SigBlk: 0000000000000000
	SigIgn: 0000000000000000
	SigCgt: 0000000000000000
	CapInh: 0000000000000000
	CapPrm: 0000000000000000
	CapEff: 0000000000000000
	CapBnd: 000001ffffffffff
	CapAmb: 0000000000000000
	NoNewPrivs:     0
	Seccomp:        0
	Seccomp_filters:        0
	Speculation_Store_Bypass:       thread vulnerable
	SpeculationIndirectBranch:      conditional enabled
	Cpus_allowed:   0fff
	Cpus_allowed_list:      0-11
	Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
	Mems_allowed_list:      0
	voluntary_ctxt_switches:        66
	nonvoluntary_ctxt_switches:     0
============================================================================
*/