// SqList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"sqlist.h"
#include"random.h"
#include"solution.h"

int main()
{
	int a[20] = { 0 };
	Rand09(a, 20);
	SqList *L;
	InitSqList(L);
	CreatSqLIst(L, a, 20);
	DispSqList(L);
	//problem one solution
	//delnode1(L, 5);
	//delnode2(L, 5);
	//problem two solution
	//move1(L);
	//move2(L);
	DispSqList(L);
    return 0;
}

