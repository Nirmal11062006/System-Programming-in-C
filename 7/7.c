#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd[2];
	pipe(fd);
	pid_t pid=fork();
	if(pid>0)
	{
		close(fd[0]);
		char a[]="Hello Child";
		write(fd[1],a,strlen(a)+1);
		close(fd[1]);
	}
	else if(pid==0)
	{
		close(fd[1]);
		char b[100];
		read(fd[0],b,sizeof(b));
		printf("message received from parent=%s\n",b);
		close(fd[0]);
	}
	else
	{
		perror("fork failed");
	}
	return 0;
}
		
