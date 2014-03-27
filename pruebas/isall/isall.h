#include <stdio.h>
#include <ctype.h>
#ifndef __ISALL_H__
#define __ISALL_H__
void alnum(char c){
	if(isalnum(c))
		printf("\nel character %c is alfanumerico",c);
	else
		printf("\nel character %c not is alfanumerico",c);
}
void digit(char c){
	if(isdigit(c))
		printf("\nel character %c is a digit",c);
	else
		printf("\nel character %c not is a digit",c);
}
#endif
