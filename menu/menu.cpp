// menu.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;
#include "MenuBase.h"
#include "LinkList.h"
#include "sort.h"
#include"tree.h"
CMenuBase*pBase;
LinkList*pList;
Sort*psort;
Tree*pTree;
void main()
{
	
	pBase = new CMainMenu;
	int EventID = 0;
	char CammandLine[255] = { 0 };
	while (pBase) {
		pBase->ShowMenu();
		cin >> CammandLine;
		if (strlen(CammandLine) == 0) {
			cout << "非法操作\n";
			break;
		}
		EventID = atoi(CammandLine);
		pBase->Event(EventID);
	}
	if (pList)
		delete pList;
	if (pTree)
		delete pTree;
}
void InvalidateAction()
{
	cout << "输入不合法\n";
}

