// SqStack.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>
#include"sqstack.h"
#include"solution.h"




int main()
{
	int i;
	char s[] = "abccba";
	SqStack *str;
	InitSqStack(str);
	for (i = 0; s[i] != '\0'; i++) {
		Push(str, s[i]);
		printf("%c ", s[i]);
	}
	printf("\n");

	printf("该字符串是%s",symmetry(s)?"对称字符串":"非对称字符串");
    return 0;
}

