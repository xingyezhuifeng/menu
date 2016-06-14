#include "StdAfx.h"
#include "LinkList.h"
#include <iostream>
using namespace std;

LinkList::LinkList() { head = new LNode; }
LinkList::LinkList(const LinkList&obj) {
	head = new LNode;
	LNode*p = head;
	LNode*q = obj.head->next;
	while (q) {
		p->next = new LNode;
		p = p->next;
		p->data = q->data;
		q = q->next;
	}
}
LinkList::~LinkList() {
	LNode*p = head;
	while (p) {
		LNode*q = p->next;
		delete p;
		p = q;
	}
	head = 0;
}
LinkList& LinkList::operator=(const LinkList &obj) {
	head = new LNode;
	LNode*p = head;
	LNode*q = obj.head->next;
	while (q) {
		p->next = new LNode;
		p = p->next;
		p->data = q->data;
		q = q->next;
	}
	return *this;
}
Status LinkList::GetElem(int i, ElemType&e) {
	LNode* p = head->next;
	int j = 1;
	while (p && j<i)
		p = p->next, ++j;
	if (!p || j>i)return ERROR;
	e = p->data;
	return OK;
}

Status LinkList::Insert(int i, ElemType e) {
	LNode* p = head;
	int j = 0;
	while (p && j<i - 1)
		p = p->next, ++j;
	if (!p || j>i - 1)return ERROR;
	LNode* s = new LNode;
	s->data = e;	s->next = p->next;	p->next = s;
	return OK;
}

Status LinkList::Delete(int i, ElemType &e) {
	LNode* p = head;
	int j = 0;
	while (p && j<i - 1)
		p = p->next, ++j;
	if (!p || j>i - 1)return ERROR;
	LNode* q = p->next;
	p->next = q->next;	e = q->data;	free(q);
	return OK;
}
LinkList LinkList::MergeList(LinkList&Lb) {
	LinkList Lc;
	LNode* pa = head->next, *pb = Lb.head->next;
	LNode* pc = Lc.head = head;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;	pc = pa; pa = pa->next;
		}
		else {
			pc->next = pb; pc = pb; pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb.head);
	Lb.head = new LNode;
	head = new LNode;
	return Lc;
}
void LinkList::Print() {
	LNode *p = head->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
