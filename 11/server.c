#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
    int sfd,cfd;
    char buf[100];
    struct sockaddr_in server;
    sfd=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(5000);
    server.sin_addr.s_addr=INADDR_ANY;
    bind(sfd,(struct sockaddr*)&server,sizeof(server));
    listen(sfd,1);
    cfd=accept(sfd,NULL,NULL);
    recv(cfd,buf,sizeof(buf),0);
    printf("Client says: %s\n",buf);
    close(cfd);
    close(sfd);
    return 0;
}
