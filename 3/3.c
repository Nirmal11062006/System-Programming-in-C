#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid=fork();
	if(pid==0)
	{
		printf("HI i am child and my pid=%d\n",getpid());
	}
	else if(pid>0)
	{
		printf("Hi this is parent=%d\n",getpid());
	}
	else
	{
	perror("fork failed");
	return 0;
	}
	return 0;
	}
