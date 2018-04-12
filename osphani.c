#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int a=0;
int b=0;
sem_t la;
sem_t lb;
void funA()
{
	sem_wait(&la);
	printf("funA is executed\n");
	if(a<2)
	{
	sem_post(&la);	
	}
	a=a+1;
//	printf("%d",a);
}
void funB()
{
	sem_wait(&lb);
printf("funB is executed\n");
  if(b<1)
	{
	sem_post(&lb);	
	}
	b=b+1;
//	printf("%d",b);
}
int main()
{
sem_init(&la,2,1);
sem_init(&lb,2,1);
pthread_t t1;
pthread_t t2;
pthread_create(&t1,NULL,funA,NULL);
pthread_create(&t2,NULL,funB,NULL);
pthread_create(&t1,NULL,funB,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t2,NULL);
pthread_join(t1,NULL);
pthread_join(t1,NULL);
}
