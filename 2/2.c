//Display the Process ID (PID) of the running program.
#include<stdio.h>
#include<unistd.h>
int main()
{
    int pid;
    pid=getpid();
    printf("PID=%d\n",pid);
    return 0;
    }
