//
//  main.cpp
//  TSMatrix
//
//  Created by 大海梦想 on 14/11/16.
//  Copyright (c) 2014年 cmsd. All rights reserved.
//

#include <iostream>

#define MAXSIZE 12500   //假设非零元个数最大值为12500
#define N 4
#define M 5

typedef int ElemType;
typedef struct {
    int i,j;
    ElemType e;
}Triple;

typedef struct {
    Triple data[MAXSIZE+1];
    int mu,nu,tu;
}TSMatrix;

void CreateSMatrix(TSMatrix &m,ElemType elem[N][M]){
    int i,j;
    m.mu=N;
    m.nu=M;
    m.tu=0;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            if (elem[i][j]!=0) {
                Triple tri;
                tri.i=i;
                tri.j=j;
                tri.e=elem[i][j];
                m.data[++m.tu]=tri;
            }
        }
    }
}

void DestorySMatrix(TSMatrix &m){
    m.mu=0;
    m.nu=0;
    m.tu=0;
}

void CopySMatrix(TSMatrix m,TSMatrix &t){
    t.mu=m.mu;
    t.nu=m.nu;
    t.tu=m.tu;
    int i;
    for (i=1; i<=m.tu; i++) {
        Triple tri;
        tri.i=m.data[i].i;
        tri.j=m.data[i].j;
        tri.e=m.data[i].e;
        t.data[i]=tri;
    }
}

void PrintSMatrix(TSMatrix m){
    int i,j;
    ElemType elem[N][M]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    for (i=1; i<=m.tu; i++) {
        elem[m.data[i].i][m.data[i].j]=m.data[i].e;
    }
    
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            printf("%2d\t",elem[i][j]);
        }
        printf("\n");
    }
}

//实现矩阵的转置
void TransposeSMatrix(TSMatrix m,TSMatrix &T){
    //...
}

int main(int argc, const char * argv[])
{
    int a[N][M]={{0,3,0,0,-5},{0,-1,0,0,0},{6,0,0,8,0},{-4,0,0,0,7}};
    TSMatrix T,S;
    CreateSMatrix(T, a);
    PrintSMatrix(T);
    TransposeSMatrix(T, S);
//    printf("转置后的矩阵为:\n");
//    PrintSMatrix(S);
    return 0;
}

