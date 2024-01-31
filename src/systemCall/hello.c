/*---------------------------------------------------------------------------
Copyright (C), 2024-2025, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: hello.c
@version: I
Creation: 19/01/2024
Last modification: 19/01/2024
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
	
int main(){
    long int checkcall = syscall(449);
	printf("System call .: sys_helloworld :. returned %1d \n",checkcall);
	return 0;
}