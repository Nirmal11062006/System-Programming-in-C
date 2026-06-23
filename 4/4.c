#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *hello(void*arg)
{
	printf("Hello from thread\n");
	return NULL;
}
int main()
{
	pthread_t t1;
	pthread_create(&t1,NULL,hello,NULL);
	pthread_join(t1,NULL);
	return 0;
	}
