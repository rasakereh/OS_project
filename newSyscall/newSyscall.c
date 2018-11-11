#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

#include "newSyscall.h"

asmlinkage long sys_getCpuId(void)
{
	return 9092201202;
}

