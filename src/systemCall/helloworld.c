/*---------------------------------------------------------------------------
Copyright (C), 2024-2025, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: helloworld.c
@version: I
Creation: 19/01/2024
Last modification: 19/01/2024
------------------------------------------------------------------------------*/
#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(helloworld)
{
    printk("Hello World.\n");
    return 0;
}