#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/shm.h>
int main()
{
	sem_t *empty,*full,*mutex;
	empty=(sem_t *)sem_open("empty",O_CREAT,0777,10);
	full=(sem_t *)sem_open("full",O_CREAT,0777,0);
	mutex=(sem_t *)sem_open("mutex",O_CREAT,0777,1);
	int i,*buff,buffsig;
	buffsig=shmget(666666,sizeof(int)*10,IPC_CREAT|0666);
	if(buffsig==-1)
	{
		printf("Share Memory Error!\n");
		return 0;
	}
	buff=(int *)shmat(buffsig,NULL,0);
	for(i=0;i<500;i++)
	{
		sem_wait(full);
		sem_wait(mutex);
		printf("%d\n",buff[i%10]);
		fflush(stdout);
		sem_post(mutex);
		sem_post(empty);
	}
	sem_unlink("empty");
	sem_unlink("full");
	sem_unlink("mutex");
	return 0;
}