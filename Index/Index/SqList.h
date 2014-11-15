//
//  SqList.h
//  Index
//
//  Created by 大海梦想 on 14/11/15.
//  Copyright (c) 2014年 cmsd. All rights reserved.
//

#ifndef Index_SqList_h
#define Index_SqList_h

#include <iostream>
#define MAXLISTSIZE 100

typedef struct {
    SLElemType data[MAXLISTSIZE];
    int length;
}SqList;

void InitList(SqList &L){
    L.length=0;
}

void Insert(SqList &L,int location,SLElemType elem){
    if (location<=L.length+1) {
        int i;
        for (i=L.length-1; i>=location-1; i--) {
            L.data[i+1]=L.data[i];
        }
        L.data[location-1]=elem;
        L.length++;
    }
}

void Delete(SqList &L,int location,SLElemType &elem){
    if (location<=L.length) {
        int i;
        elem=L.data[i-1];
        for (i=location; i<L.length; i++) {
            L.data[i-1]=L.data[i];
        }
        L.length--;
    }
}

void GetElem(SqList L,int location,SLElemType &elem){
    if (location<=L.length) {
        elem=L.data[location-1];
    }
}



#endif
