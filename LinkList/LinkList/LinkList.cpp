// LinkList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"linklist.h"
#include"random.h"
#include"solution.h"


int main()
{
	int a[20] = { 0 };
	int b[10] = {
		1,2,3,5,8,6,4,2,9,0
	};
	LinkList *A;
	Rand09(a, 20);
	Printr(a, 20);
	LinkList *L;
	InitLinkList(L);
	CreateLinkListF(L, a, 20);
	DispLinkList(L);
	CreateLinkListR(L, a, 20);
	DispLinkList(L);
	
	InitLinkList(A);
	CreateLinkListF(A, b, 10);
	DispLinkList(A);
	delmaxnode(A);
	DispLinkList(A);
    return 0;
}

