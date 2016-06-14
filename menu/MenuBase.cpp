#include "StdAfx.h"
#include "MenuBase.h"
#include "resource.h"
#include"sort.h"
#include"tree.h"
#include <iostream>
using namespace std;
extern CMenuBase*pBase;

CMenuBase::CMenuBase(void) :m_pParent(NULL)
{
}
CMenuBase::~CMenuBase(void)
{
}
void CMainMenu::ShowMenu() {
	cout << "\n **************《数据结构课程设计》*****************\n";
	cout << "  *  1 线性表  2 栈与队列  3 串、数组和义表       *\n";
	cout << "  *  4 树      5 图        6 查找                 *\n";
	cout << "  *  7 排序    8 退出                             *\n";
	cout << "  ***************************************************\n";
}
void CMainMenu::Event(int EvenID) {
	CMenuBase*tmp;
	switch (EvenID) {
	case ID_LIST:
		SUBMENU(CListMenu)
			break;
	case ID_SORT:
		SUBMENU(CSortMenu)
		break;
	case ID_TREE:
		SUBMENU(CTreeMenu)
			break;
	case ID_EXIT:
		delete pBase;
		pBase = 0;
		break;
	default:
		InvalidateAction();
		break;
	}
}
#include "LinkList.h"
extern LinkList*pList;
CListMenu::CListMenu(CMenuBase*parent) {
	m_pParent = parent;
}

CListMenu::~CListMenu(void)
{
}
extern Sort*psort;
CSortMenu::CSortMenu(CMenuBase*parent) {
	m_pParent = parent;
}
CSortMenu::~CSortMenu(void) {	
}
CSortMenu1::CSortMenu1(CMenuBase*parent)
{
	m_pParent = parent;
}
CSortMenu1::~CSortMenu1(void)
{
}

void CListMenu::ShowMenu() {
	cout << "  ************《线性表》*************\n";
	cout << "  *  1 创建线性表  2 插入元素       *\n";
	cout << "  *  3 查找元素    4 删除元素       *\n";
	cout << "  *  5 浏览        6 退出           *\n";
	cout << "  ***********************************\n";
}
void CSortMenu::ShowMenu() {
	cout << "  ************《排序》*************\n";
	cout << "  *  1 输入数据  2 插入排序       *\n";
	cout << "  *  3 快速排序  4 Shell排序      *\n";
	cout << "  *  5 冒泡排序 6其他排序 7退出      *\n";
	cout << "  *********************************\n";
}
void CSortMenu1::ShowMenu() {
	cout << "请选择哪种插入排序\n";
	cout << "  ************《其他排序》*************\n";
	cout << "  *  1 选择排序  2 堆排序排序       *\n";
	cout << "  *    3退出     *\n";
	cout << "  *********************************\n";
}
void CSortMenu1::Event(int EvenID)
{
	CMenuBase*tmp;
	switch (EvenID)
	{
	case 3:
			EXIT_SUBMENU;
	default:
		break;
	}
	
}
void CSortMenu1::OnSortInsert()
{
}
extern Tree*pTree;
CTreeMenu::CTreeMenu(CMenuBase*parent)
{
	m_pParent = parent;
}
CTreeMenu::~CTreeMenu(void)
{
}
void CTreeMenu::ShowMenu() {
	cout << "  ****************************《树和二叉树》***********************\n";
	cout << "  *  1 创建树         2 先序遍历树     3 中序遍历树  4 后序遍历树*\n";
	cout << "  *   5 创建赫夫曼树	 6 得到赫夫曼编码 7 退出                    *\n";
	cout << "  *****************************************************************\n";
}

void CListMenu::Event(int EvenID) {
	CMenuBase*tmp;
	switch (EvenID) {
	case ID_CREATE_LIST:
		OnCreateList();
		break;
	case ID_LIST_INSERT:
		OnListInsert();
		break;
	case ID_LIST_DELET:
		OnListDelete();
		break;
	case ID_LIST_FIND:
		OnListFind();
		break;
	case ID_LIST_SHOW:
		OnListShow();
		break;
	case ID_LIST_RETURN:
		EXIT_SUBMENU
			break;
	default:
		InvalidateAction();
		break;
	}
}
void CSortMenu::Event(int EvenID) {
	CMenuBase*tmp;
	switch (EvenID) {
	case ID_SORT_BUBBLE:
		OnSortBublle();
		break;
	case ID_SORT_INSERT:
		OnSortInsert();
		break;
	case ID_SORT_QUICK:
		OnSortQuick();
		break;
	case ID_SORT_SHELL:
		OnSortShell();
		break;
	case ID_SORT_SHOW:
		OnSortShow();
		break;
	case ID_SORT_QITA:
		SUBMENU(CSortMenu1)
			break;
	case ID_SORT_RETURN:
		EXIT_SUBMENU
			break;
	default:
		InvalidateAction();
		break;
	}
}
void CTreeMenu::Event(int EvenID) {
	CMenuBase*tmp;
	switch (EvenID) {
	case ID_CREATE_TREE :
		OnCreateBiTree();
		break;
	case ID_PREORDER_TREE :
		OnPreOrderTraverse();
		break;
	case ID_INORDER_TREE :
		OnInOrderTraverse();
		break;
	case ID_POSTORDER_TREE:
		OnPostOrderTraverse();
		break;
	case ID_HUFFMAN_TREE:
		OnHuffmanCoding();
		break;
	case ID_HUFFMANCODE_TREE:
		OnHuffmanShow();
		break;
	case ID_TREE_RETURN:
		EXIT_SUBMENU
			break;
	default:
		InvalidateAction();
		break;
	}
}
void CTreeMenu::OnCreateBiTree()
{
	if (pTree)
	{
		cout << "树早已经创建了";
		return;
	}

	pTree = new Tree();
	pTree->CreateBiTree((pTree->T));
	cout << "树创建好了";
}
void CTreeMenu::OnPreOrderTraverse()
{
	if (!pTree)
	{
		cout << "先创建树才能先序遍历";
		return;
	}
	pTree->PreOrderTraverse((pTree->T));
}
void CTreeMenu::OnInOrderTraverse()
{
	if (!pTree)
	{
		cout << "先创建树才能中序遍历";
		return;
	}
	pTree->InOrderTraverse((pTree->T));
}
void CTreeMenu::OnPostOrderTraverse()
{
	if (!pTree)
	{
		cout << "先创建树才能后序遍历";
		return;
	}
	pTree->PostOrderTraverse((pTree->T));
}
void CTreeMenu::OnHuffmanCoding()
{
	cout << "请先输入个数";
	cin >> z;

	cout << "请依次输入权重";
	for (int q = 0; q<z; q++)
		cin >> a[q];
	pTree->HuffmanCoding(a, z, s);
	cout << "赫夫曼编码完成";
}
void CTreeMenu::OnHuffmanShow()
{
	for (int i = 1; i <= z; ++i)
	{
		cout << "第" << i << "个字符的编码为";
		cout << (s[i]) << endl;
	}
}
void CListMenu::OnCreateList() {
	if (pList) {
		cout << "链表已创建\n";
		return;
	}
	pList = new LinkList;
	cout << "链表创建成功\n";
}

void CListMenu::OnListInsert() {
	if (!pList) {
		cout << "必须先创建链表才能插入元素\n";
		return;
	}
	cout << "输入要插入的整数";
	int a;
	cin >> a;
	if (pList->Insert(1, a) == OK)
		cout << "插入成功\n";
	else
		cout << "插入失败\n";
}
void CListMenu::OnListFind() {
	if (!pList)
	{
		cout << "必须先创建链表才能查找元素\n";
		return;
	}
	cout << "输入要寻找的整数的位置";
	int a, e;
	cin >> a;
	if (pList->GetElem(a, e) == OK)
		cout << "查找成功，该处的值为:" << e << "\n";
	else
		cout << "查找失败\n";
}
void CListMenu::OnListDelete() {
	if (!pList) {
		cout << "必须先创建链表并插入元素" << endl;
		return;
	}
	cout << "输入要删除的元素的位置";
	int a;
	int b;
	cin >> a;
	if (pList->Delete(a, b) == OK)
		cout << "删除元素" << b << endl;
	else
		cout << "删除失败\n";
}
void CListMenu::OnListShow() {
	if (!pList) {
		cout << "没有创建表\n";
		return;
	}
	pList->Print();
}
void CSortMenu::OnSortInsert() {
	psort->Insert(a-1, n);
	for (int i = 0; i <n; i++) {
		cout << a[i] << endl;
	}
}
void CSortMenu::OnSortBublle() {
	psort->BublleSort(a, n);
	for (int i = 0; i <n; i++) {
		cout << a[i] << endl;
	}
}
void CSortMenu::OnSortQuick() {
	psort->QuickSort(a-1,1,n);
	for (int i = 0; i <n; i++) {
		cout << a[i] << endl;
	}
}
void CSortMenu::OnSortShell() {
	
	psort->ShellSort(a,n);
	for (int i = 0; i <n; i++) {
		cout << a[i] << endl;
	}
}
void CSortMenu::OnSortShow() {
	
	cout<<"请输入n";
	cin >> n;
	a = new int[n];
	for (int i = 0; i <n; i++) {
		cin >> a[i];
	}
	cout << "请选择排序" << endl;

}