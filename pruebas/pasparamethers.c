#include <stdio.h>
#include <pthread.h>
typedef struct test{
	long int idthread;
	void *autocue[2];
}test;
void *testFunction(void *args){
	test *hcab=args[0];
	hcab->idthread=pthread_self();
	printf("\nsoy el hilo %d,con id=%ld",(int)args[1],hcab->idthread);
//	printf("\n%s!!!\t%s!!",hcab->autocue[0],hcab->autocue[1]);
	pthread_exit(NULL);
}
int main(){
	test cab;
	unsigned char i;
	char phrase[11]={"\nhola mundo"},name[9]={"\nsoy ayan"};
	void *references[2];
	pthread_t thread[11];
	cab.autocue[0]=&phrase;
	cab.autocue[1]=&name;
	for(i=0;i<11;i++){
		references[0]=&cab;
		references[1]=&i;	
		pthread_create(&thread[i],NULL,testFunction,(void *)references);
	}
	printf("\n");return 0;
}
