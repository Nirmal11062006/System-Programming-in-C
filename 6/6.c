#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t sem;
void*print(void*arg)
{
	sem_wait(&sem);
	printf("hellow from thread\n");
	sem_post(&sem);
}
int main()
{
	pthread_t t1,t2;
	sem_init(&sem,0,1);
	pthread_create(&t1,NULL,print,NULL);
	pthread_create(&t2,NULL,print,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&sem);
	return 0;
	}
	
