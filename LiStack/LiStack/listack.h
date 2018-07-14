#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct linknode {
	ElemType data;
	struct linknode *next;
}LiStack;

void InitLiStack(LiStack *&s)
{
	s = (LiStack*)malloc(sizeof(LiStack));
	s->next = NULL;
}

void DestroyLiStack(LiStack *&s)
{
	LiStack *p = s, *q = s->next;
	while (q != NULL) {
		free(q);
		p = q;
		q = p->next;
	}
	free(q);
}

bool ListackEmpty(LiStack *s)
{
	return s->next == NULL;
}

bool Push(LiStack *&s, ElemType e)
{
	LiStack *p;
	p = (LiStack)malloc(sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool Pop(LiStack *&s, ElemType &e)
{
	LiStack *p;
	if (s->next == NULL) {
		return false;
	}
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LiStack *s, ElemType &e)
{
	if (s->next == NULL) {
		return false;
	}
	e = s->next->data;
	return true;
}