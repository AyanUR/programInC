#include <stdio.h>
#include <stdlib.h>
#include "strall.h"
#define tamano 50
int main(){
	int menu;
	initCad();
	do{
		printf("\n\n1 strcasecmp\n2 strstr\n3 strcat\n4 strchr\n5 strpbrk\n6 strcmp\n7 strcoll\n8 strcpy\n9 strcspn\n10 strdup\n11 strdupa\n12 stream\n 13 stream.im6\n14 strerror\n15 strerror_r\n16 strfmon\n17 strfry\n18 strftime\n19 string\n20 strings\n21 strip\n22 strlen\n23 strncasecmp\n24 strtok\n25 strtok_r\n26 salir\n\n");
		scanf("%d",&menu);
		switch(menu){
			case 1:casecmp();break;
			case 2:str();break;
			case 3:cat();break;
			case 4:chr();break;
			case 5:pbrk();break;
			case 24:tok();break;
			case 25:tok_r();break;
			case 26:printf("\n\t\tasta pronto ...");break;
			default: printf("\nesa no es una opcion :S");
		}
	}while(menu!=26);
	puts("");return 0;
}
