#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
unsigned char flat=0;
void *calcTime(void *args){
	struct timeval start,end;
	int time=0;
	gettimeofday(&start,NULL);
	while(time<=100&&!flat){
		gettimeofday(&end,NULL);
		time=(((end.tv_sec-start.tv_sec)*1000)+((end.tv_usec-start.tv_usec)/1000));
		printf("\ntime=%d",time);
	}
	flat=1;
	pthread_exit(NULL);
}
void *reciv(void *args){
	int cta=0;
	while(cta<=70&&!flat){
		cta++;
	}
	pthread_exit(NULL);
}
int main(int ari,char **arc){
	//int wait=100;
	//sscanf(arc[1],"%d",&wait);
	pthread_t hilo[2];
	pthread_create(&hilo[0],NULL,reciv,NULL);
	pthread_create(&hilo[1],NULL,calcTime,NULL);
	pthread_join(hilo[0],NULL);
	pthread_join(hilo[1],NULL);
	printf("\n");return 0;
}
