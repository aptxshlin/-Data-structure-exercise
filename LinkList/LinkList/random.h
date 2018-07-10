#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Rand09(int r[], int n)
{
	int i;
	srand((int)time(NULL));
	for (i = 0; i < n; i++) {
		r[i] = rand() % 10;
	}
}

void Printr(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
