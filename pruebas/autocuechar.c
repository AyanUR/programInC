#include <stdio.h>
#include <string.h>
void twoautocue(){
	char data[2][6];
	strcpy(data[0],"\nhola");
	strcpy(data[1],"\nmundo");
	printf("\ndata[0]=%s",data[0]);
	printf("\ndata[1]=%s",data[1]);
}
char *cut(char *cadena){
	return "hola";
}
void getEntity(char *cadena,char *entity){
	sscanf(cadena,"E-%[a-zA-Z=-9 -]_F",entity);
}
void entidad(){
	char entity[30];
	char cad[110]={"E-Alumno_F[s-(boleta),c-(nombreCompleto:s-(nombre),s-(apPat),s-(apMat)),k-(boleta)].\n"};
	getEntity(cad,entity);
	printf("\n|entity=%s|",entity);
	printf("\n|cad=%s|",cad);
}
void funstrcpy(){
	char arc[30],saludo[11]={"hola mundo"};
	strcpy(arc,(saludo+5));
	printf("\narc=%s",arc);
}
int main(){
	funstrcpy();
	printf("\n");return 0;
}
