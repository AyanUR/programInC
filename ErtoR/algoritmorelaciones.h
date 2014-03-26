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
		if(strchr(entity->data,'*')!=NULL){
			memcpy(key[i++],entity->data,strlen(entity->data)-1);
			//if(flat)//quitamos * y &
			//	key[i-1][strlen(key)-2]=' ';
		}
	}
}
void putPunterosinEntity(char *entityone,char *entitytwo,list **eone,list **etwo){//eone and etwo no nulos
	while(strcmp(entityone,(*eone)->data)&&(*eone=(*eone)->down)!=NULL);
		//*eone=(*eone)->down;
	while(strcmp(entitytwo,(*etwo)->data)&&(*etwo=(*etwo)->down)!=NULL);
//		*etwo=(*etwo)->down;
}
void passKey(list **entity,char key[][tamano]){
	int i=0;
	while(key[i++][0]!=0)
		addElementLast(entity,key[i-1]);
}
void relacion(list **table,char *relacion){
	//cursa-Alumno,Materia|m:n|t-p|s-attrsimples
	int i=0;
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
	printf("\neone->data=%s",entityone->data);
	printf("\netwo->data=%s",entitytwo->data);
	saveKeyEntity(entityone,entitykeyone);
	saveKeyEntity(entitytwo,entitykeytwo);
	while(entitykeyone[i++][0]!=0)	
		printf("\nentitykeyone[%d]=%s",i,entitykeyone[i-1]);
	for(i=0;entitykeytwo[i][0]!=0;i++)
		printf("\nentitykeytwo[%d]=%s",i,entitykeytwo[i]);
	if(info[1][0]=='<'&&info[2][0]=='<'){//son fuertes
		printf("\nson fuertes\n");
if(info[3][0]=='1'&&(info[4][0]=='n'||(info[4][0]=='1'&&(info[5][0]==info[6][0]||(info[5][0]=='p'&&info[6][0]=='t')))))
	passKey(entitytwo,entitykeyone);
	if((info[3][0]=='m'&&info[4][0]=='n')||(info[3][0]=='n'&&info[4][0]=='m'))
		createTable();
	return;
	}
	if(info[1][0]=='>'&&info[2][0]=='>'){//son deviles
		printf("\nson deviles");
		return;
	}
	//una es devil y la otra fuerte
	
}
#endif
