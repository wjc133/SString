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

void InsertL(LinkList L,ElemType elem){
    LNode *p=(LNode*)malloc(sizeof(LNode));
    p->next;
    p->data=elem;
    LNode *q=L;
    while (q->next!=NULL) {
        q=q->next;
    }
    q->next=p;
}

void InsertF(LinkList L,ElemType elem){
    LNode* p=(LNode*)malloc(sizeof(LNode));
    p->next=L->next;
    p->data=elem;
    L->next=p;
}

void InsertNode(LinkList L,int location,ElemType elem){
    LNode *p=L;
    int i=1;
    while (i<location) {
        i++;
        p=p->next;
    }
    LNode *q=(LNode*)malloc(sizeof(LNode));
    q->data=elem;
    q->next=p->next;
    p->next=q;
}

void DeleteNode(LinkList L,int location,ElemType &elem){
    LNode *p=L->next;
    int i=1;
    while (i<location) {
        i++;
        p=p->next;
    }
    LNode *q=p->next;
    elem=q->data;
    p->next=q->next;
    free(q);
}

void GetElem(LinkList L,int location,ElemType &elem){
    LNode *p=L->next;
    int i=1;
    while (i<=location) {
        i++;
        p=p->next;
    }
    elem=p->data;
}

#endif
