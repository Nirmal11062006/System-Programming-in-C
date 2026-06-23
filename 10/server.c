#include<stdio.h>
#include<fcntl.h>
#include<mqueue.h>
#include<unistd.h>
#include<string.h>
struct mq_attr attr={
	.mq_flags=0,
	.mq_maxmsg=10,
	.mq_msgsize=100,
	.mq_curmsgs=0
	};
int main()
{
mqd_t send, reply;
send=mq_open("/send",O_CREAT|O_RDONLY,0666,&attr);
reply=mq_open("/reply",O_CREAT|O_WRONLY,0666,&attr);
char a[100];
mq_receive(send,a,sizeof(a),NULL);
printf("%s\n",a);
char msg[]="reply from server";
mq_send(reply,msg,strlen(msg)+1,0);
mq_close(send);
mq_close(reply);
mq_unlink("/send");
mq_unlink("/reply");
return 0;
}

