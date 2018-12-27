/*
 * Copyright 2006 Andi Kleen, SUSE Labs.
 * Subject to the GNU Public License, v.2
 *
 * Fast user context implementation of getcpu()
 */

#include <linux/kernel.h>
#include <linux/getcpu.h>
#include <linux/time.h>
#include <asm/vgtod.h>

notrace long
__vdso_oscpuid(void)
{
	long a = 1, b;

	__asm__("cpuid"
		:"=a"(b)                 // EAX into b (output)
		:"0"(a)                  // a into EAX (input)
		:"%ebx","%ecx","%edx");  // clobbered registers

	return b;
}

long oscpuid(void)
	__attribute__((weak, alias("__vdso_oscpuid")));


