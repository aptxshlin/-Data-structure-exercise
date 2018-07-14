#pragma once

#include<stdio.h>
#include<stdlib.h>
#include"listack.h"

bool Match(ElemType exp[], int n)
{
	int i = 0; ElemType e;
	bool match = true;
	LiStack *st;
	InitLiStack(st);
	while (i < n&&match) {
		if (exp[i] == '(') {
			Push(st, exp[i]);
		}
		else if (exp[i] = ')') {
			if (GetTop(st, e) == true) {
				if (e != '(') {
					match = false;
				}
				else {
					Pop(st, e);
				}
			}
			else {
				match = false;
			}
		}
		i++;
	}
	if (ListackEmpty(st)) {
		match = false;
	}
	DestroyLiStack(st);
	return match;
}