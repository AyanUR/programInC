#include <stdio.h>
#include <string.h>
#define tamano 50
#define anidado 11
#define atribute 7
int main(){
	int i;
	char compuestos[anidado][atribute][tamano];
	bzero(compuestos,anidado*atribute*tamano*sizeof(char));
	for(i=0;i<7;i++)
		strcpy(compuestos[i][0],"hola mundo");
	for(i=0;compuestos[i][0][0]!=0;i++)
		printf("\ncompuestos[%d]=%s",i,compuestos[i][0]);
	puts("");return 0;
}
