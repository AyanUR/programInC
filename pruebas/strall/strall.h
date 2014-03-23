#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef __STRALL_H__
#define __STRALL_H__
#define tamano 50
char *cadone,*cadtwo;
void pideOneString(char *cadone,char *character){
	printf("\ningrese la primera cadena   ");
	getchar();
	gets(cadone);
	printf("\ningrese un caracter ");
	scanf("%c",character);
}
void pideTwoString(char *cadone,char *cadtwo){
	printf("\ningrese la primera cadena   ");
	getchar();
	gets(cadone);
	printf("\ningrese la segunda cadena   ");
	gets(cadtwo);
}
void initCad(){
	cadone=(char *)malloc(tamano*sizeof(char));
	cadtwo=(char *)malloc(tamano*sizeof(char));
}
void muestraloescrito(){
	printf("\nprimera = %s",cadone);
	printf("\nsegunda = %s",cadtwo);
}
void casecmp(){
	pideTwoString(cadone,cadtwo);
	muestraloescrito();
	printf("\n e comparado tus cadenas sin importar las minusculas o mallusculas y son ");
	if(!strcasecmp(cadone,cadtwo)){
		printf("iguales");
	}else{
		printf("diferentes");
	}
}
void str(){
	char *substring;
	pideTwoString(cadone,cadtwo);
	muestraloescrito();
	printf("\ne buscado la subcadena %s en la cadena %s y ",cadtwo,cadone);
	if((substring=(char *)strstr(cadone,cadtwo))!=NULL)
		printf(" si esta %s",substring);
	else
		printf("no la encontre :(");
}
void cat(){
	unsigned char cta=50;
	pideTwoString(cadone,cadtwo);
	muestraloescrito();
	printf("\ne concatendado las cadenas y el resultado es %s",strcat(cadone,(char *)&cta));
}
void chr(){
	char character,*index;
	pideOneString(cadone,&character);
	index=strchr(cadone,character);
	printf("\ne buscado el caracter %c en la cadena %s y ",character,cadone);
	if(index!=NULL)
		printf("si esta %s",index);
	else
		printf("no esta :(");
}
void pbrk(){
	char *index;
	pideTwoString(cadone,cadtwo);
	index=strpbrk(cadone,cadtwo);
	printf("\nebuscado todos los caracteres de la cadena %s en la cadena %s y ",cadtwo,cadone);
	if(index!=NULL)
		printf("si esta la primera ocurrencia fue %c",*index);
	else
		printf("no esta :(");
	
}
void tok(){
	int i;
	printf("\ningresa una cadena");
	getchar();
	gets(cadone);
	printf("\ningrese el caracter o cadena delimitador");
	gets(cadtwo);
	muestraloescrito();
	for(i=0;i<4;i++){
		if(i==0){
			printf("\n%d=%s",i,strtok(cadone,cadtwo));
			continue;
		}
		printf("\n%d=%s",i,strtok(NULL,cadtwo));
	}
}
void tok_r(){
	int i;
	char **ptrptr;
	ptrptr=(char **)malloc(tamano*sizeof(char *));
	for(i=0;i<tamano;i++)
		ptrptr[i]=(char *)malloc(tamano*sizeof(char));
	printf("\ningresa una cadena");
	getchar();
	gets(cadone);
	printf("\ningrese el caracter o cadena delimitador");
	gets(cadtwo);
	muestraloescrito();
	for(i=0;i<4;i++){
		if(i==0){
			printf("\n%d=%s",i,strtok_r(cadone,cadtwo,&ptrptr[i]));
			continue;
		}
		printf("\n%d=%s",i,strtok_r(ptrptr[i],cadtwo,&ptrptr[i]));
	}
	printf("\nempisa la matriz");
	for(i=0;i<4;i++)
		printf("\n%d=%s",i,ptrptr[i]);
}
#endif
