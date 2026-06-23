#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
	int shmid=shmget(1234,1024,0666);
	char*ptr=shmat(shmid,NULL,0);
	printf("data retrived from memory=%s\n",ptr);
	shmdt(ptr);
	return 0;
	}
