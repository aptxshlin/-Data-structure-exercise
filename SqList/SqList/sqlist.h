#pragma once

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length = 0;
}SqList;

void CreatSqLIst(SqList *&L, ElemType a[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		L->data[i] = a[i];
	}
	L->length = n;
}

void InitSqList(SqList *&L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

void DestroySqList(SqList *&L)
{
	free(L);
}

bool SqListEmpty(SqList *L)
{
	return (L->length == 0);
}

int SqListLength(SqList *L)
{
	return (L->length);
}

void DispSqList(SqList *L)
{
	int i;
	if (SqListEmpty(L))return;
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

bool GetElem(SqList *L, int i, ElemType &e)
{
	if (i<1 || i>L->length)return false;
	e = L->data[i - 1];
	return true;
}

int LocateElem(SqList *L, ElemType e)
{
	int i = 0;
	while (i < L->length&&L->data[i] != e)
		i++;
	if (i >= L->length)return 0;
	else return i + 1;
}

bool SqListInsert(SqList *&L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length)return false;
	i--;
	for (j = L->length; j > i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;
}

bool SqListDelete(SqList *&L, int i, ElemType &e)
{
	int j;
	if (i<1 || i>L->length)return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length; j++) {
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}

