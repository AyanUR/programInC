#include <stdio.h>
#include "isall.h"
int main(){
	int menu;
	char character;
	do{
		printf("\n\t1 isalnum\n\t2 isdigit\n\t3 salir\n");
		scanf("%d",&menu);
		getchar();
		if(menu!=3){
			printf("\ningrese un caracter\n");
			scanf("%c",&character);
		}
		switch(menu){
			case 1:alnum(character);break;
			case 2:digit(character);break;
			case 3:printf("\n\tasta pronto ...");break;
		}
	}while(menu!=3);
	puts("");return 0;
}
