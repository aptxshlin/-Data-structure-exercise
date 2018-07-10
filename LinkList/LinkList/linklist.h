#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkList;

void CreateLinkListF(LinkList *&L, ElemType a[], int n)
{
	LinkList *s;
	int i;
	//L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
	for (i = 0; i < n; i++) {
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreateLinkListR(LinkList *&L, ElemType a[], int n)
{
	LinkList *s, *r;
	int i;
	//L = (LinkList*)malloc(sizeof(LNode));
	r = L;
	for (i = 0; i < n; i++) {
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void InitLinkList(LinkList *&L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
}

void DestroyLInkList(LinkList *&L)
{
	LinkList *pre = L, *p = L->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool LinkListEmpty(LinkList *L)
{
	return L->next == NULL;
}

int LinkListLength(LinkList *L)
{
	LinkList *p = L;
	int n = 0;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

void DispLinkList(LinkList *L)
{
	LinkList *p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

bool GetElem(LinkList *&L, int i, ElemType &e)
{
	int j = 0;
	LinkList *p = L;
	while (j < i && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	else {
		e = p->data;
		return true;
	}
}

int LocateElem(LNode *L, ElemType e)
{
	int i = 1;
	LinkList *p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL)return 0;
	else return i;
}

bool LinkListInsert(LinkList *&L, int i, ElemType e)
{
	int j = 0;
	LinkList *p = L, *s;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)return false;
	else {
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool LinkListDelete(LinkList *&L, int i, ElemType &e)
{
	int j = 0;
	LinkList *p = L, *q;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)return false;
	else {
		q = p->next;
		p->next = q->next;
		free(q);
		return true;
	}
}

