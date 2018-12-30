#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <ctime>
#include <cerrno>
using namespace std;
int phil[5]={0,1,2,3,4};
int state[5];
sem_t mutex;
sem_t S[5];
void test(int phnum)
{
	if (state[phnum]==1 && state[(phnum+1)%5]!=0 && state[(phnum+4)%5]!=0)
	{
		state[phnum]=0;
		usleep(2*1000);
		cout<<"philospher"<<phnum+1<<" is eating"<<endl;
		sem_post(&S[phnum]);
	}
}
void take_fork(int phnum)
{
	sem_wait(&mutex);
	state[phnum]=1; //1 for hungry;
	cout<<"philospher"<<phnum+1<<" is hungry"<<endl;
	test(phnum);
	sem_post(&mutex);
	sem_wait(&S[phnum]);
	sleep(1);
}
void put_fork(int phnum)
{
	sem_wait(&mutex);
	state[phnum]=2;
	cout<<"Philospher"<<phnum+1<<" is thinking"<<endl;
	test((phnum+1)%5);
	test((phnum+4)%5);
	sem_post(&mutex);
}
void *philospher(void *num)
{
	while(1)
	{
		int* i=(int* )num;
		sleep(1);
		take_fork(*i);
		sleep(0);
		put_fork(*i);
	}
}
int main()
{
	pthread_t t_id[5];
	sem_init(&mutex,0,1);
	for(int i=0;i<5;i++)
	{
		sem_init(&S[i],0,1);
	}
	for(int i=0;i<5;i++)
	{
		pthread_create(&t_id[i],NULL,philospher,&phil[i]);
		cout<<"philospher"<<i+1<<" is thinking"<<endl;
	}
	for(int i=0;i<5;i++)
	{
		pthread_join(t_id[i],NULL);
	}

}