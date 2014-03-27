#include <stdio.h>
#include <string.h>
#ifndef __ALGORITMORELACIONES_H__
#define __ALGORITMORELACIONES_H__
#define tamano 70//tamaño de las cadenas
#define anidado 11//numero maximo de anidaciones de una tributo compuesto numero de bloques
#define atribute 11//numero maximo de atributos del atributo compuesto numero de palabras
list *enespera=NULL,*auxespera,*strong=NULL;
void saveKeyEntity(list *entity,char key[][tamano]){
	int i=0;
	while((entity=entity->next)!=NULL){
		if(strchr(entity->data,'*')!=NULL){
			if(strchr(entity->data,'&')!=NULL)
				memcpy(key[i++],entity->data,strlen(entity->data)-1);
			else
				memcpy(key[i++],entity->data,strlen(entity->data));
		}
	}
}
void putPunterosinEntity(char *entityone,char *entitytwo,list **eone,list **etwo){//eone and etwo no nulos
	while(strcasecmp(entityone,(*eone)->data)&&(*eone=(*eone)->down)!=NULL);
	while(strcasecmp(entitytwo,(*etwo)->data)&&(*etwo=(*etwo)->down)!=NULL);
}
void passKey(list **entity,char key[][tamano],unsigned char flat,char *simple){
	int i=0;
	while(key[i++][0]!=0){
		if(flat)
			key[i-1][strlen(key[i-1])-2]=' ';
		addElementLast(entity,strcat(key[i-1],"$"));
	}
	if(simple[0]!=0){
        	addElementLast(entity,strtok(simple,","));
       		 while((simple=strtok(NULL,","))!=NULL)
                	addElementLast(entity,simple);
	}
}
void createTable(list **table,char *relacion,char *eone,char *etwo,char keyone[][tamano],char keytwo[][tamano],char *simple){
	int i=0;
	list *aux=NULL;
	char nametable[tamano]={0};
	strcat(strcat(strcat(nametable,eone),relacion),etwo);
	addElementLast(&aux,nametable);
	while(keyone[i++][0]!=0)
		addElementLast(&aux,keyone[i-1]);
	i=0;
	while(keytwo[i++][0]!=0)
		addElementLast(&aux,keytwo[i-1]);
	if(simple[0]!=0){
        	addElementLast(&aux,strtok(simple,","));
       		 while((simple=strtok(NULL,","))!=NULL)
                	addElementLast(&aux,simple);
	}
	addRowforTable(table,&aux);
}
void Strong(list **table,list **eone,list **etwo,char keyone[][tamano],char keytwo[][tamano],char info[][tamano]){
	if(info[3][0]=='1'&&(info[4][0]=='n'||(info[4][0]=='1'&&(info[5][0]==info[6][0]||(info[5][0]=='p'&&info[6][0]=='t')))))//1:n,1t:1t,1p:1p,1p:1t
		passKey(etwo,keyone,1,&info[7][2]);
	if((info[3][0]=='n'&&info[4][0]=='1')||(info[3][0]=='1'&&info[5][0]=='t'&&info[4][0]=='1'&&info[6][0]=='p'))//n:1,1t:1p
		passKey(eone,keytwo,1,&info[7][2]);
	if((info[3][0]=='m'&&info[4][0]=='n')||(info[3][0]=='n'&&info[4][0]=='m'))//m:n
		createTable(table,info[0],&info[1][1],&info[2][1],keyone,keytwo,&info[7][2]);
}
void strongDevil(list **table,list **eone,list **etwo,char keyone[][tamano],char keytwo[][tamano],char info[][tamano]){//por default tienes que pasarle la llave del fuerte al devil
	if(info[1][0]=='<'&&info[2][0]=='>'){//eone fuerte , etwo devil
		addElementLast(&strong,&info[2][1]);
		passKey(etwo,keyone,0,&info[7][2]);
	}
	else{//eone devil etwo fuerte
		addElementLast(&strong,&info[1][1]);
		passKey(eone,keytwo,0,&info[7][2]);
	}
	if((info[3][0]=='m'&&info[4][0]=='n')||(info[3][0]=='n'&&info[4][0]=='m'))
		createTable(table,info[0],&info[1][1],&info[2][1],keyone,keytwo,&info[7][2]);	
}
void devil(list **table,list **eone,list **etwo,char keyone[][tamano],char keytwo[][tamano],char info[][tamano],char *relacion){
	if(exist(strong,&info[1][1])==NULL){
		if(exist(strong,&info[2][1])==NULL){
			if(exist(enespera,relacion)==NULL)
				addElementLast(&enespera,relacion);
		}
		else{
			info[2][0]='<';
			//printf("\n\t\tla fuerte fue %s",info[2]);
			//printf("\n\t\tetwo->data %s",(*etwo)->data);
			bzero(keytwo,tamano*sizeof(char));
			saveKeyEntity(*etwo,keytwo);
			//printf("\n\t\tkeytwo %s",keytwo[4]);
			strongDevil(table,eone,etwo,keyone,keytwo,info);
		}
	}else{
		printf("\n\t\tla fuerte fue %s",info[2]);
		info[1][0]='<';
		bzero(keyone,tamano*sizeof(char));
		saveKeyEntity(*eone,keyone);
		strongDevil(table,eone,etwo,keyone,keytwo,info);
	}
}
void relacion(list **table,char *relacion){	//cursa-Alumno,Materia|m:n|t-p|s-attrsimples
	char info[8][tamano],entitykeyone[anidado][tamano],entitykeytwo[anidado][tamano];
	list *entityone=*table,*entitytwo=*table;
	bzero(info,8*tamano*sizeof(char));
	bzero(entitykeyone,anidado*tamano*sizeof(char));
	bzero(entitykeytwo,anidado*tamano*sizeof(char));
	sscanf(relacion,"%[a-zA-Z0-9_]-%[a-zA-Z0-9_><],%[a-zA-Z0-9_><]|%c:%c|%c:%c|%s",info[0],info[1],info[2],&info[3][0],&info[4][0],&info[5][0],&info[6][0],info[7]);
	putPunterosinEntity(&info[1][1],&info[2][1],&entityone,&entitytwo);
	saveKeyEntity(entityone,entitykeyone);
	saveKeyEntity(entitytwo,entitykeytwo);
	if(info[1][0]=='<'&&info[2][0]=='<'){//son fuertes
		Strong(table,&entityone,&entitytwo,entitykeyone,entitykeytwo,info);return; }
	if(info[1][0]=='>'&&info[2][0]=='>'){//son deviles
		devil(table,&entityone,&entitytwo,entitykeyone,entitykeytwo,info,relacion);return ;}
	//una es devil y la otra fuerte
	strongDevil(table,&entityone,&entitytwo,entitykeyone,entitykeytwo,info);
}
#endif
