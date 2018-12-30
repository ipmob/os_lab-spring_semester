//wap in c to implement reader's writers problem with n readers & n writers

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define N 5

int b;
int readcount;
sem_t mutex,wrt;
void* w()
{
	printf("\nWriter function called");
	int i=1;
	for(i=0;i<N;i++)
	{
		sem_wait(&wrt);             //wait
		b=i;
		i++;
		//Writing is performed
		printf("\nwritten, shared variable = %d",b);
		sem_post(&wrt);             //signal
		printf("\nWriter Sleeping");
		sleep(1);
	}
	printf("\nWriter is leaving\n");
}
void * r(void * a)
{
	printf("\nReader function called");
	int *rr =(int *) a ;
	int i;
	for(i=0;i<N;i++)
	{
		sem_wait(&mutex);
		readcount++;
		if(readcount==1)
			sem_wait(&wrt);
			
		sem_post(&mutex);
		//Readind is performed
		printf("\nReader func :read=%d Reader no.=%d ",b,*rr);
		printf("\nReader %d : Sleeping",*rr);
		sleep(1);
		sem_wait(&mutex);
		readcount--;
		if(readcount==0)             //to check last reader
			sem_post(&wrt);
		sem_post(&mutex);
	}
	printf("\nReader no.= %d is leaving\n",*rr);
}

void main()
{
	pthread_t w1,w2,r1,r2;
	int rr1=1,rr2=2;
	b=0;
	readcount=0;
	printf("\nInitial Value of shared variable %d",b);
	sem_init(&(wrt),0,1);
	sem_init(&(mutex),0,1);
	//Creating Threads
	pthread_create(&w1,NULL,w,NULL);
	pthread_create(&r1,NULL,r,(void * )&rr1);
	pthread_create(&r2,NULL,r,(void * )&rr2);
	pthread_join(w1,NULL);
	pthread_join(r1,NULL);
	pthread_join(r2,NULL);
}



