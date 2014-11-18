//
//  main.cpp
//  CrossList
//
//  Created by 大海梦想 on 14/11/17.
//  Copyright (c) 2014年 cmsd. All rights reserved.
//

#include <iostream>

typedef struct OLNode{
    int i,j;
    int e;
    OLNode *right,*down;
}OLNode, *OLink;

typedef struct {
    OLink *rhead,*chead;
    int mu,nu,tu;
}CrossList;

void AddSMatrix_OL(CrossList &A,CrossList B){
    int j;
    OLink pa,pb,pre,hl[A.nu+1];
    pa=A.rhead[1];
    pb=A.chead[1];
    pre=NULL;
    for (j=1; j<=A.nu; j++) {
        hl[j]=A.chead[j];
    }
}

void CreateSMatrix_OL(CrossList &C){
    int m,n,t;
    scanf("%d%d%d",&m,&n,&t);
    C.mu=m;C.nu=n;C.tu=t;
    if (!(C.rhead=(OLink*)malloc(sizeof(OLink)*(m+1)))) {
        exit(1);
    }
    if (!(C.chead=(OLink*)malloc(sizeof(OLink)*(n+1)))) {
        exit(1);
    }
    int p;
    int i,j,e;
    OLink o,q;
    for (p=1; p<=m; p++) {
        C.rhead[p]=NULL;
    }
    for (p=1; p<=n; p++) {
        C.chead[p]=NULL;
    }
    for (scanf("%d%d%d",&i,&j,&e); i!=0; scanf("%d%d%d",&i,&j,&e)) {
        if (!(o=(OLink)malloc(sizeof(OLNode)))) {
            exit(1);
        }
        o->i=i; o->j=j; o->e=e;
        if (C.rhead[i]==NULL||C.rhead[i]->j>j) {
            o->right=C.rhead[i];
            C.rhead[i]=o;
        }else{
            //查询在行表中的插入位置
            for (q=C.rhead[i]; (q->right)&&q->right->j<j; q=q->right);
            o->right=q->right;
            q->right=o;
        }
        //列插入
        if (C.chead[j]==NULL||C.chead[j]->i>i) {
            o->down=C.chead[j];
            C.chead[j]=o;
        }else{
            //查询在列表中的插入位置
            for (q=C.chead[j]; (q->down)&&(q->down->i<i); q=q->down);
            o->down=q->down;
            q->down=o;
        }
    }
}

int main(int argc, const char * argv[])
{
    CrossList C;
    CreateSMatrix_OL(C);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

