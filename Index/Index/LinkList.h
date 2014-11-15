//
//  LinkList.h
//  Index
//
//  Created by 大海梦想 on 14/11/15.
//  Copyright (c) 2014年 cmsd. All rights reserved.
//

#ifndef Index_LinkList_h
#define Index_LinkList_h

#include <iostream>

typedef struct LNode{
	ElemType data;
	LNode* next;
}LNode,*LinkList;

void InitList(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	if(!L) exit(0);
	L->next=NULL;
}

#endif
