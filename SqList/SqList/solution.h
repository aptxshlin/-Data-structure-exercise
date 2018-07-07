#pragma once

#include<stdio.h>
#include"sqlist.h"

// problem 1
/*
已知长度为n的线性表A采用顺序存储结构。设计
一个时间复杂度为O(n)、空间复杂度为O(1)的算法，
该算法删除线性表中所有值为x的数据元素。
*/

// solution 1.1
/*
解法一：设删除A中所有值等于x元素后的顺序表为A1，
显然A1包含在A中，为此A1重用A的空间。
思路：扫描顺序表A，重建A只包含不等于x的元素。
*/

void delnode1(SqList *&A, ElemType x)
{
	int k = 0, i;
	for (i = 0; i < A->length; i++) {
		if (A->data[i] != x) {
			A->data[k] = A->data[i];
			k++;
		}
	}
	A->length = k;
}

//solution 1.2
/*
解法二：用k记录顺序表A中等于x的元素个数，
一边扫描A一边统计k值。
思路：将不为x的元素前移k个位置，最后修改A的长度。
*/
void delnode2(SqList *&A, ElemType x)
{
	int k = 0, i = 0;
	while (i < A->length) {
		if (A->data[i] == x) {
			k++;
		}else {
			A->data[i - k] = A->data[i];
		}
		i++;
	}
	A->length -= k;
}

//problem 2
/*
设顺序表L有10个整数。设计一个算法，
以第一个元素为分界线（基准），
将所有小于等于它的元素移到该元素的前面，
将所有大于它的元素移到该元素的后面。
*/
//solution 2.1
/*
pivot=L->data[0]（基准）
j从后向前找≤pivot的元素
i从前向后找>pivot的元素
*/
void move1(SqList *&L)
{
	int i = 0, j = L->length - 1;
	ElemType tmp;
	ElemType privot = L->data[0];
	while (i < j) {
		while (i < j && L->data[j] > privot)
			j--;
		while (i < j && L->data[i] <= privot)
			i++;
		if (i < j) {
			tmp = L->data[i];
			L->data[i] = L->data[j];
			L->data[j] = tmp;
		}
	}
	tmp = L->data[0];
	L->data[0] = L->data[j];
	L->data[j] = tmp;
}

// solution 2.2
/*
pivot=L->data[0]（基准）
j从后向前找小于等于pivot的元素：前移
i从前向后找大于pivot的元素：后移
*/
void move2(SqList *&L)
{
	int i = 0, j = L->length - 1;
	ElemType privot = L->data[0];
	while (i < j) {
		while (j > i&&L->data[j] > privot)
			j--;
		L->data[i] = L->data[j];
		while (i < j&&L->data[i] <= privot)
			i++;
		L->data[j] = L->data[i];
	}
	L->data[i] = privot;
}