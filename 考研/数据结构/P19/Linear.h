#pragma once
#include<iostream>
#include <cstdio>
#include<cstdlib>
typedef int Status;

#define maxn 100

typedef int ElemType;
typedef struct {
	ElemType data[maxn]; //数组基地址类型
	int length;			//线性表长度 1,2,3...
}List;
