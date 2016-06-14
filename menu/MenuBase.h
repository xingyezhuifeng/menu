#pragma once
#pragma once
#include<iostream>
using namespace std;
class CMenuBase
{
public:
	CMenuBase(void);
	~CMenuBase(void);
	virtual void ShowMenu() = 0;
	virtual void Event(int EvenID) = 0;
protected:
	CMenuBase* m_pParent;
};
class CMainMenu :public CMenuBase
{
public:
	CMainMenu(void) {};
	~CMainMenu(void) {};
	virtual void ShowMenu();
	virtual void Event(int EvenID);

};
class CListMenu :public CMenuBase
{
public:
	CListMenu(CMenuBase*);
	~CListMenu(void);
	virtual void ShowMenu();
	virtual void Event(int EvenID);
protected:
	void OnCreateList();
	void OnListInsert();
	void OnListDelete();
	void OnListFind();
	void OnListShow();
};
class CSortMenu :public CMenuBase
{
public:
	CSortMenu(CMenuBase*);
	~CSortMenu(void);
	virtual void ShowMenu();
	virtual void Event(int EvenID);
	int *a;
	int n;
protected:
	void OnSortInsert();
	void OnSortShell();
	void OnSortQuick();
	void OnSortBublle();
	void OnSortShow();
};
class CTreeMenu :public CMenuBase
{
public:
	int a[100];
	char**s;
	int z;
	CTreeMenu(CMenuBase*);
	~CTreeMenu(void);
	virtual void ShowMenu();
	virtual void Event(int EvenID);

protected:
	void OnCreateBiTree();
	void OnPreOrderTraverse();
	void OnInOrderTraverse();
	void OnPostOrderTraverse();
	void OnHuffmanCoding();
	void OnHuffmanShow();
};
class CSortMenu1 :public CMenuBase
{
public:
	CSortMenu1(CMenuBase * parent);
	~CSortMenu1(void);
	virtual void ShowMenu();
	virtual void Event(int EvenID);
	int *a;
	int n;
protected:
	void OnSortInsert();
	
};