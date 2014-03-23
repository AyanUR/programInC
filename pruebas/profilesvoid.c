#include <stdio.h>
int main(){
	void **pv=NULL;
	char h='h';
	*pv=(void *)&h;
	printf("\npv = %c",*((char*)*pv));
	printf("\n");return 0;
}
