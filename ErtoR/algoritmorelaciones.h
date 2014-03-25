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
			memcpy(key[i++],entity->data,sizeof(entity->data)-1);
			if(flat)//quitamos * y &
				key[i-1][strlen(key)-2]=' ';
		}
	}
}
void putPunteros(char *entityone,char *entitytwo,list **eone,list **etwo){//eone and etwo no deven ser nulo
	while(!strcmp(entityone,eone->data)&&eone!=NULL)
		eone=eone->down;
	while(!strcmp(entitytwo,etwo->data)&&etwo!=NULL)
		etwo=etwo->down;
}
void cardinalidad(){
}
void relacion(char *relacion){
	//cursa-Alumno,Materia|m:n|t-p|s-attrsimples
	int i;
	char info[8][tamano];
	bzero(info,8*tamano*sizeof(char));
	sscanf(relacion,"%[a-zA-Z0-9_]-%[a-zA-Z0-9_><],%[a-zA-Z0-9_><]|%c:%c|%c:%c|%s",info[0],info[1],info[2],&info[3][0],&info[4][0],&info[5][0],&info[6][0],info[7]);
	if(info[1][0]=='<'&&info[2][0]=='<'){//son fuertes
		
		return;
	}
	if(info[1][0]=='>'&&info[2][0]=='>'){//son deviles
		return;
	}
	//una es devil y la otra fuerte
	
}
#endif
