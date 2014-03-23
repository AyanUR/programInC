#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
void escrive(int dscptor){
	char text[700];
	printf("\ningrese el texto que desea guardar en el archivo\n");
	scanf("%s",text);
	write(dscptor,text,(strlen(text)*sizeof(char)));
}
void lee(int dscptor){
	char text[700];
	while(read(dscptor,text,sizeof(char))!=0){
		printf("%s",text);
	}
}
int main(){
	int descriptor;
	unsigned char menu;
	char namefile[30];
	printf("\ningrese el nombre del archivo de texto con todo y extencion\n");
	scanf("%s",namefile);//no lee el salto de linea asi como gets pero fgets si lo lee
	if((descriptor=open(namefile,O_CREAT|O_WRONLY,0777))==-1){
		printf("\nerror al abrir el archivo");
		printf("\n");return 1;
	}
	do{
		printf("\npresione\n\t1 escribir\n\t2 leer\n\t3 salir\n");
		getchar();
		scanf("%d",(int *)&menu);
		switch(menu){
			case 1:escrive(descriptor);break;
			case 2:break;
			case 3:printf("\n\n\t\tasta pronto :D");break;	
			default:printf("\nporfavor esa no es una opcion (las opciones son 1,2,3)");
		}
	}while(menu!=3);
	close(descriptor);
	printf("\n");return 0;
}
