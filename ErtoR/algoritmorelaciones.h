#include <stdio.h>
#include <string.h>
#ifndef __ALGORITMORELACIONES_H__
#define __ALGORITMORELACIONES_H__
#define tamano 50//tamaño de las cadenas
#define anidado 11//numero maximo de anidaciones de una tributo compuesto numero de bloques
#define atribute 11//numero maximo de atributos del atributo compuesto numero de palabras
void saveKeyEntity(list *entity,char key[][tamano]){
	int i=0;
	while((entity=entity->next)!=NULL){
		if(strchr(entity->data,'*')!=NULL)
			memcpy(key[i++],entity->data,strlen(entity->data)-1);
	}
}
void putPunterosinEntity(char *entityone,char *entitytwo,list **eone,list **etwo){//eone and etwo no nulos
	while(strcmp(entityone,(*eone)->data)&&(*eone=(*eone)->down)!=NULL);
	//*eone=(*eone)->down;
	while(strcmp(entitytwo,(*etwo)->data)&&(*etwo=(*etwo)->down)!=NULL);
	// *etwo=(*etwo)->down;
}
void passKey(list **entity,char key[][tamano],unsigned char flat){
	int i=0;
	while(key[i++][0]!=0){
		if(flat)
			key[i-1][strlen(key[i-1])-2]=' ';
		addElementLast(entity,key[i-1]);
	}
}
void createTable(list **table,char *relacion,char *eone,char *etwo,char keyone[][tamano],char keytwo[][tamano]){
	int i=0;
	list *aux=NULL;
	char nametable[tamano]={0};
	strcat(strcat(strcat(nametable,eone),relacion),etwo);
	//printf("\nnametable=%s",nametable);
	addElementLast(&aux,nametable);
	while(keyone[i++][0]!=0)
		addElementLast(&aux,keyone[i-1]);
	i=0;
	while(keytwo[i++][0]!=0)
		addElementLast(&aux,keytwo[i-1]);
	addRowforTable(table,&aux);
}
void relacion(list **table,char *relacion){	//cursa-Alumno,Materia|m:n|t-p|s-attrsimples
	char info[8][tamano],entitykeyone[anidado][tamano],entitykeytwo[anidado][tamano];
	list *entityone=*table,*entitytwo=*table;
	bzero(info,8*tamano*sizeof(char));
	bzero(entitykeyone,anidado*tamano*sizeof(char));
	bzero(entitykeytwo,anidado*tamano*sizeof(char));
	sscanf(relacion,"%[a-zA-Z0-9_]-%[a-zA-Z0-9_><],%[a-zA-Z0-9_><]|%c:%c|%c:%c|%s",info[0],info[1],info[2],&info[3][0],&info[4][0],&info[5][0],&info[6][0],info[7]);
	/*
		indice 0 nombre de la recacion
		indice 1 y 2 nombre de las tablas
		indice [3][0] y [4][0] cardinalidad de entidad 1 y cardinalidad de entidad 2
		indice [5][0] y [6][0] participacion de entidad 1 y participacion de entidad 2
		indice [7] los atributos de la relacion
	*/
	putPunterosinEntity(&info[1][1],&info[2][1],&entityone,&entitytwo);

	saveKeyEntity(entityone,entitykeyone);
	saveKeyEntity(entitytwo,entitykeytwo);

	if(info[1][0]=='<'&&info[2][0]=='<'){//son fuertes
		printf("\nson fuertes\n");
		if(info[3][0]=='1'&&(info[4][0]=='n'||(info[4][0]=='1'&&(info[5][0]==info[6][0]||(info[5][0]=='p'&&info[6][0]=='t')))))//1:n,1t:1t,1p:1p,1p:1t
			passKey(&entitytwo,entitykeyone,1);
		if((info[3][0]=='n'&&info[4][0]=='1')||(info[3][0]=='1'&&info[5][0]=='t'&&info[4][0]=='1'&&info[6][0]=='p'))//n:1,1t:1p
			passKey(&entityone,entitykeytwo,1);
		if((info[3][0]=='m'&&info[4][0]=='n')||(info[3][0]=='n'&&info[4][0]=='m'))//m:n
			createTable(table,info[0],&info[1][1],&info[2][1],entitykeyone,entitykeytwo);
		return;
	}
	if(info[1][0]=='>'&&info[2][0]=='>'){//son deviles
		printf("\nson deviles");
		return;
	}
	//una es devil y la otra fuerte
	printf("\nuna es devil y otra fuerte");
	//por default tienes que pasarle la llave del fuerte al devil
	if(info[1][0]=='<'&&info[2][0]=='>')//eone fuerte , etwo devil
		passKey(&entitytwo,entitykeyone,0);
	else//eone devil etwo fuerte
		passKey(&entityone,entitykeytwo,0);
//if((info[3][0]=='n'&&info[4][0]=='1')||(info[3][0]=='1'&&info[5][0]=='t'&&info[4][0]=='1'&&info[6][0]=='p'))
		// passKey(&entityone,entitykeytwo);
	if((info[3][0]=='m'&&info[4][0]=='n')||(info[3][0]=='n'&&info[4][0]=='m'))
		createTable(table,info[0],&info[1][1],&info[2][1],entitykeyone,entitykeytwo);	
}
#endif
