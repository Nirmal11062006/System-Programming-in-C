#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
	int shmid;
	shmid=shmget(1234,1024,IPC_CREAT|0666);//key,size,flag
	char*ptr=shmat(shmid,NULL,0);//atach
	strcpy(ptr,"Hello from shared memory");
	printf("Data Written\n");
	shmdt(ptr);//detach;
	return 0;
	}
