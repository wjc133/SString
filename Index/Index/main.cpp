//
//  main.cpp
//  Index
//
//  Created by 大海梦想 on 14/11/15.
//  Copyright (c) 2014年 cmsd. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  TRUE   1
#define  FALSE   0
#define  OK    1
#define  ERROR   0
#define  OVERFLOW  -1


#define  MaxBookNum  1000    //假设只对1000本书建立索引表
#define  MaxKeyNum  2500    //索引表的最大容量
#define  MaxLineLen  500     //书目串的最大长度
#define  MaxWordNum  10     //词表的最大容量
typedef  int  ElemType ; //定义链表数据元素类型为整型(书号类型)
