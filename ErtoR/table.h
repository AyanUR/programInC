#include <stdio.h>
#include "simplelist.h"
#ifndef __TABLE_H__
#define __TABLE_H__
void showTable(list *table){
	list *p,*q;
	for(p=table;p!=NULL;p=p->down){
		for(q=p;q!=NULL;q=q->next)
			printf("|%s",q->data);
		printf("|\n");
	}
}
void addRowforTable(list **table,list **cab){
	list *p,*q;
	if(*table==NULL)
		*table=*cab;
	else{
		for(p=*table;p->down!=NULL;p=p->down){;}
		for(q=*cab;p!=NULL&&q!=NULL;p=p->next,q=q->next){
			p->down=q;
			q->up=p;
		}
	}
}
#endif
