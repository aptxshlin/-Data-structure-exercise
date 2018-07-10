#pragma once

#include<stdio.h>
#include"linklist.h"


//设计一个算法，删除一个单链表L中元素值最大的 节点（假设最大值节点是唯一的）。
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

//有一个带头节点的单链表L（至少有一个数据节 点），设计一个算法使其元素递增有序排列。

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

//假设有一个带头节点的单链表L={a1,a2,…,an}。设 计一个算法将所有节点逆置.
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
假设有一个带头节点的单链表L={a1，b1，a2， b2，…，an，bn}。
设计一个算法将其拆分成两个带头节点的单链表 L1和L2：
L1={a1，a2，…，an}，L2={bn，bn-1，…，b1} 要求L1使用L的头节点。
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