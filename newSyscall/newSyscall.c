#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

#include "newSyscall.h"

asmlinkage long sys_getCpuId(void)
{
  	unsigned int eax, ebx, ecx, edx;
	eax = 3; /* EAX=3: Processor Serial Number */
	ebx = 0;
	ecx = 0;
	edx = 0;
 	/* For Intel Pentium III CPUs, the serial number is returned in the EDX:ECX registers.
	 For Transmeta Efficeon CPUs, it is returned in the EBX:EAX registers.
	 And for Transmeta Crusoe CPUs, it is returned in the EBX register only. */
        asm volatile("cpuid"
            : "=a" (*eax),
              "=b" (*ebx),
              "=c" (*ecx),
              "=d" (*edx)
            : "0" (*eax), "2" (*ecx));

	return ebx; /* Transmeta Efficeon CPU ID */
}

