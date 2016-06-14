#pragma once
#pragma once
#include "def.h"
class Tree {
	typedef struct BiTNode {
		char  data;
		BiTNode *lchild, *rchild;
	}BiTNode, *BiTree;


	typedef struct {
		unsigned int weight;
		unsigned int parent, lchild, rchild;
	}HTNode, *HuffmanTree;
	typedef char * *HuffmanCode;

public:
	BiTree T;
	Tree();
	~Tree();
	char * strcpy(char * strDest, const char * strSrc);
	int Visit(char e);

	int CreateBiTree(BiTree &T);
	int PreOrderTraverse(BiTree S);
	int InOrderTraverse(BiTree S);
	int PostOrderTraverse(BiTree S);
	int HuffmanCoding(int *w, int n, char * *&s);
	int Select(HuffmanTree HT, int t, int&s1, int&s2);

};