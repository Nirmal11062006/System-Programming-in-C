#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<mqueue.h>
#include<string.h>
int main()
{
mqd_t send,reply;
send=mq_open("/send",O_WRONLY);
reply=mq_open("/reply",O_RDONLY);
char a[]="hello from client";
mq_send(send,a,strlen(a)+1,0);
char buff[100];
mq_receive(reply,buff,sizeof(buff),NULL);
printf("%s \n ",buff);
mq_close(send);
mq_close(reply);
return 0;
}
