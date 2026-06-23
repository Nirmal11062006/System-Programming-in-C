#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	mkfifo("fifo1",0666);
	int fd=open("fifo1",O_WRONLY);
	char msg[]="hello reader";
	write(fd,msg,strlen(msg)+1);
	close(fd);
	return 0;
}
