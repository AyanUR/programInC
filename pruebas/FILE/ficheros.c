#include <stdio.h>
typedef struct expediente{
	char name[21];
	char boleta[10];
	char phone[10];
	int nota;
}expediente;
void escrivir(FILE **file){
	expediente a={"ayan","2012630450","5540027762",8};
	expediente b={"marizol","2012630150","5558928904",10};
	expediente c={"alejandra","2012630350","5525168497",9};
	expediente alumnos[3]={a,b,c};
	//fwrite(datos,tamañodeldato,cuantosdatos,FILE);
	//fwrite("hola",4*sizeof(char),4,*file);
	fwrite(alumnos,sizeof(expediente),3,*file);
	printf("\ne guardado 3 alumnos ");
}
void leer(FILE **file){
	expediente alumno;
	/*
		fseek(FILE,numerodebytesamoverse,desdedondesemovera);
		SEEK_SET  se regresa al principio del archivo y empisa a moverse el numero de bite que le indimemos
		SEEK_END  se posisiona
		SEEL_CUR  no mueve el puntero se queda en donde esta y empiesa a moverse el numero de bytes que le dijimos
	*/
	//ftell(FILE); regresa en numero de byte en la posission en la que se encuentra
	/*
		fread(direccionendondeguardaremoslosdatos,numerodebytesaguardar,cuantasvesesguardaremoselnumerodebytes,FILE);
	*/
	fseek(*file,sizeof(expediente),);
	

}
int main(int ari,char **arc){//./a.out test.bin w
	FILE *file;
	if(ari<3){
		printf("\n./nombreEjecutable nombreArchivo.extencion mododeapertura(w,a,r,a+...)");
		puts("");return 1;
	}
	if((file=fopen(arc[1],arc[2]))==NULL){
		printf("\nerror cant open file");
		puts("");return -1;
	}
	escrivir(&file);
	fclose(file);
	puts("");return 0;
}
