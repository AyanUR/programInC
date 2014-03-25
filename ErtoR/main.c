#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "algoritmoentidades.h"
#include "simplelist.h"
#include "table.h"
int main(int ari,char **arc){
	FILE *pf;
	char line[tamano];
	list *cab=NULL,*table=NULL;
	if(ari<2){
		fprintf(stderr,"\nejecute como $%s archivoEntidadRelacion",arc[0]);
		puts("");return 1;
	}
	if((pf=fopen(arc[1],"r"))==NULL){
		printf("\nerror al abrir %s",arc[1]);
		puts("");return 1;
	}
	bzero(compuestos,anidado*atribute*tamano*sizeof(char));
	while((fscanf(pf,"%s",line))!=EOF)
		whatIs(&cab,&table,line);
	//showList(cab);
	//showCompuestos();
	showTable(table);
	fclose(pf);
	puts("");return 0;
}
