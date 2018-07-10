#pragma once

#include<stdio.h>
#include"linklist.h"


//���һ���㷨��ɾ��һ��������L��Ԫ��ֵ���� �ڵ㣨�������ֵ�ڵ���Ψһ�ģ���
void delmaxnode(LinkList *&L)
{
	DispLinkList(L);
	LinkList *p = L->next, *pre = L, *maxp = p, *maxpre = pre;
	printf("#1 p:%d maxp:%d p->next->data:%d\n", p->data, maxp->data, p->next->data);
	while (p != NULL) {
		printf(" #2 p:%d maxp:%d p->next->data:%d\n", p->data, maxp->data, p->next->data);
		if (maxp->data <= p->data) {
			maxp = p;
			maxpre = pre;
			printf("#3 p:%d maxp:%d p->next->data:%d\n", p->data, maxp->data, p->next->data);
		}
		p = pre;
		p = p->next;
		printf("#4 p:%d maxp:%d\n", p->data, maxp->data);
	}
	maxpre->next = maxp->next;
	free(maxpre);
}

//��һ����ͷ�ڵ�ĵ�����L��������һ�����ݽ� �㣩�����һ���㷨ʹ��Ԫ�ص����������С�

void sort(LinkList *&L)
{
	LinkList *p, *pre, *q;
	p = L->next->next;
	L->next->next = NULL;
	while (p != NULL) {
		q = p->next;
		pre = L;
		while (pre != NULL && pre->next->data < p->data) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

//������һ����ͷ�ڵ�ĵ�����L={a1,a2,��,an}���� ��һ���㷨�����нڵ�����.
void Reverse(LinkList *&L)
{
	LinkList *p = L->next, *q;
	L->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

/*
������һ����ͷ�ڵ�ĵ�����L={a1��b1��a2�� b2������an��bn}��
���һ���㷨�����ֳ�������ͷ�ڵ�ĵ����� L1��L2��
L1={a1��a2������an}��L2={bn��bn-1������b1} Ҫ��L1ʹ��L��ͷ�ڵ㡣
*/

void split(LinkList *&L, LinkList *&L1, LinkList *&L2)
{
	LinkList *p = L->next, *q, *r1;
	L1 = L;
	r1 = L1;
	L2 = (LinkList*)malloc(sizeof(LinkList));
	L2->next = NULL;
	while (p != NULL)
	{
		r1->next = p;
		r1 = p;
		p = p->next;
		q = p->next;
		p->next = L2->next;
		L2->next = p;
		p = q;
	}
	r1->next = NULL;
}