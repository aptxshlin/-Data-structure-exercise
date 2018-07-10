#pragma once

#include<stdio.h>
#include<stdlib.h>

#define MAXSIEZ 50
typedef char ElemType;
typedef struct {
	ElemType data[MAXSIEZ];
	int top;
}SqStack;

void InitSqStack(SqStack *&s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestroySqStack(SqStack *&s)
{
	free(s);
}

bool SqStackEmpty(SqStack *s)
{
	return s->top == -1;
}

bool Push(SqStack *&s, ElemType e)
{
	if (s->top == MAXSIEZ - 1) {
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack *&s, ElemType &e)
{
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack *s, ElemType &e)
{
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return true;
}