/*---------------------------------------------------------------------------
Copyright (C), 2024-2025, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: secondEx.c
@version: I
Creation: 19/01/2024
Last modification: 19/01/2024
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>

int main(){
	int f = (int)fork();

	if (f == 0) {	
		execl("./fex", (char*)NULL);}
		else {
		printf("%d\n", (int)getpid());
		execl("./fex", (char*)NULL);}
}
