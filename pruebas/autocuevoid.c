#include <stdio.h>
void test(void **args){
	printf("\nla funcion test recivio:");
	printf("\n%s!!!\t%d!!",(char *)args[0],(int)args[1]);
}
int main(){
	char thrase[10]={"hola mundo"};
	void *references[2];
	references[0]=&thrase;
	references[1]=(void *)3;
	test(references);
	printf("\n");return 0;
}
