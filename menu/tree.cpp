#include "stdafx.h"
#include "tree.h"
#include <iostream>
#include<assert.h>
using namespace std;
Tree::Tree() {}
Tree::~Tree() {}
char* Tree::strcpy(char*strDest, const char*strSrc) {
	assert((strDest != NULL) && (strSrc != NULL));
	char*address = NULL;
	address = strDest;
	while ((*strDest++ = *strSrc++));
	return address;
}
 int Tree::Visit(char e)
{
	cout << e;
	return OK;
}
 int Tree::CreateBiTree(BiTree &T)
{
	char  ch;
	cin >> ch;


	if (ch == '~')
	{
		T = NULL;
	}
	else 
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);

	}
	return OK;
}
int Tree::PreOrderTraverse(BiTree T)
{
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild))
				if (PreOrderTraverse(T->rchild))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
int Tree::InOrderTraverse(BiTree T)
{
	if (T)
	{
		if (InOrderTraverse(T->lchild))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
int Tree::PostOrderTraverse(BiTree T)
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild))
			if (PostOrderTraverse(T->rchild))
				if (Visit(T->data))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
int Tree::HuffmanCoding(int *w, int n, char * *&s)
{
	if (n <= 1)
		return 0;
	int m = 2 * n - 1;
	int s1;
	int s2;
	HuffmanTree HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	
	int i;
	for (i = 1; i <= n; i++) { //初始化     
		HT[i].weight = w[i - 1];
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (; i <= m; ++i)
	{
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= m; ++i)
	{
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	s = (HuffmanCode)malloc((n + 1) * sizeof(char *));
	char * cd = (char *)malloc(n * sizeof(char));    // 分配求编码的工作空间    
	cd[n - 1] = '\0';                         // 编码结束符。   
	int start;
	int c;
	int f;
	for (i = 1; i <= n; ++i)
	{                  // 逐个字符求哈夫曼编码      
		start = n - 1;                          // 编码结束符位置     
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)        // 从叶子到根逆向求编码        
			if (HT[f].lchild == c) cd[--start] = '0';
			else
				cd[--start] = '1';
		s[i] = (char *)malloc((n - start) * sizeof(char));           // 为第i个字符编码分配空间      
		strcpy(s[i], &cd[start]);

	}
	free(HT);
	free(cd);
	// 释放工作空间
	return OK;
}
int Tree::Select(HuffmanTree HT, int t, int&s1, int&s2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int least = 0;
	int second = 0;
	for (i = 1; i <= t; i++)
	{
		if (HT[i].parent == 0)
			break;
	}
	for (j = i + 1; j <= t; j++)
	{
		if (HT[j].parent == 0)
			break;
	}
	if (HT[i].weight<HT[j].weight)
	{
		least = i;
		second = j;
	}
	else
	{
		least = j;
		second = i;
	}
	for (k = j + 1; k <= t; k++)
	{
		if (HT[k].parent == 0)
		{
			if (HT[k].weight<HT[least].weight)
			{
				second = least;
				least = k;
			}
			else
				if (HT[k].weight >= HT[least].weight&&HT[k].weight<HT[second].weight)
					second = k;
		}
	}
	s1 = least;
	s2 = second;
	return OK;
}
