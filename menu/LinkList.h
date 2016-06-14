#pragma once
#include "def.h"
class LinkList {
	typedef int ElemType;
	struct LNode {
		ElemType data;
		struct LNode*next;
		LNode() :next(0) {}
	}*head;
public:
	LinkList();
	LinkList(const LinkList&obj);
	~LinkList();
	LinkList& operator=(const LinkList &obj);
	Status GetElem(int i, ElemType&e);
	Status Insert(int i, ElemType e);
	Status Delete(int i, ElemType &e);
	LinkList MergeList(LinkList&Lb);
	Status Find(int i);
	void Print();
};
