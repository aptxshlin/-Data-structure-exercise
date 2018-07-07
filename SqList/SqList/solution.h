#pragma once

#include<stdio.h>
#include"sqlist.h"

// problem 1
/*
��֪����Ϊn�����Ա�A����˳��洢�ṹ�����
һ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨��
���㷨ɾ�����Ա�������ֵΪx������Ԫ�ء�
*/

// solution 1.1
/*
�ⷨһ����ɾ��A������ֵ����xԪ�غ��˳���ΪA1��
��ȻA1������A�У�Ϊ��A1����A�Ŀռ䡣
˼·��ɨ��˳���A���ؽ�Aֻ����������x��Ԫ�ء�
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
�ⷨ������k��¼˳���A�е���x��Ԫ�ظ�����
һ��ɨ��Aһ��ͳ��kֵ��
˼·������Ϊx��Ԫ��ǰ��k��λ�ã�����޸�A�ĳ��ȡ�
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
��˳���L��10�����������һ���㷨��
�Ե�һ��Ԫ��Ϊ�ֽ��ߣ���׼����
������С�ڵ�������Ԫ���Ƶ���Ԫ�ص�ǰ�棬
�����д�������Ԫ���Ƶ���Ԫ�صĺ��档
*/
//solution 2.1
/*
pivot=L->data[0]����׼��
j�Ӻ���ǰ�ҡ�pivot��Ԫ��
i��ǰ�����>pivot��Ԫ��
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
pivot=L->data[0]����׼��
j�Ӻ���ǰ��С�ڵ���pivot��Ԫ�أ�ǰ��
i��ǰ����Ҵ���pivot��Ԫ�أ�����
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