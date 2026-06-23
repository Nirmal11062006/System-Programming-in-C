#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t lock;
void *print(void*arg)
{
	pthread_mutex_lock(&lock);
	printf("hello from thread\n");
	pthread_mutex_unlock(&lock);
	return NULL;
	
}
int main()
{
	pthread_t t1,t2;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&t1,NULL,print,NULL);
	pthread_create(&t2,NULL,print,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
	}
