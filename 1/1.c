#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd;
	fd=open("test.txt",O_CREAT|O_RDWR,0666);
	char ar[]={"Hello Linux"};
	int n=write(fd,&ar,sizeof(ar));
	if(n<0)
	{
		perror("write failed");
		return 0;
	}
	lseek(fd,0,SEEK_SET);
	char a[100];
	int b=read(fd,&a,sizeof(a)-1);
	a[b]='\0';
	if(b<0)
	{
		perror("read failed");
		return 0;
	}
	printf("%s",a);
	return 0;
	}
