#pragma once

#include<stdio.h>
#include<stdlib.h>
#include"sqstack.h"

bool symmetry(ElemType str[])
{
	int i;
	ElemType e;
	SqStack *st;
	InitSqStack(st);
	printf("%s\n", str);
	for (i = 0; str[i] != '\0'; i++) {
		Push(st, str[i]);
		printf("%c ", str[i]);
	}
	printf("\n");
	printf("%s\n", str);
	for (i = 0; str[i] != '\0'; i++) {
		printf("%c\n",str[i]);
		Pop(st, e);
		printf("%c %c\n", str[i], e);
		if (str[i] != e) {
			printf("false\n");
			printf("%c %c\n", str[i], e);
			DestroySqStack(st);
			return false;
		}
	}
	DestroySqStack(st);
	return true;
}
