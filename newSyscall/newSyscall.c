#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

#include "newSyscall.h"

asmlinkage long sys_getCpuId(void)
{
	long a = 1, b;

	__asm__("cpuid"
		:"=a"(b)                 // EAX into b (output)
		:"0"(a)                  // a into EAX (input)
		:"%ebx","%ecx","%edx");  // clobbered registers

	return b;
}

