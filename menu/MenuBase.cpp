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
	cout << "\n **************�����ݽṹ�γ���ơ�*****************\n";
	cout << "  *  1 ���Ա�  2 ջ�����  3 ������������       *\n";
	cout << "  *  4 ��      5 ͼ        6 ����                 *\n";
	cout << "  *  7 ����    8 �˳�                             *\n";
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
	cout << "  ************�����Ա�*************\n";
	cout << "  *  1 �������Ա�  2 ����Ԫ��       *\n";
	cout << "  *  3 ����Ԫ��    4 ɾ��Ԫ��       *\n";
	cout << "  *  5 ���        6 �˳�           *\n";
	cout << "  ***********************************\n";
}
void CSortMenu::ShowMenu() {
	cout << "  ************������*************\n";
	cout << "  *  1 ��������  2 ��������       *\n";
	cout << "  *  3 ��������  4 Shell����      *\n";
	cout << "  *  5 ð������ 6�������� 7�˳�      *\n";
	cout << "  *********************************\n";
}
void CSortMenu1::ShowMenu() {
	cout << "��ѡ�����ֲ�������\n";
	cout << "  ************����������*************\n";
	cout << "  *  1 ѡ������  2 ����������       *\n";
	cout << "  *    3�˳�     *\n";
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
	cout << "  ****************************�����Ͷ�������***********************\n";
	cout << "  *  1 ������         2 ���������     3 ���������  4 ���������*\n";
	cout << "  *   5 �����շ�����	 6 �õ��շ������� 7 �˳�                    *\n";
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
		cout << "�����Ѿ�������";
		return;
	}

	pTree = new Tree();
	pTree->CreateBiTree((pTree->T));
	cout << "����������";
}
void CTreeMenu::OnPreOrderTraverse()
{
	if (!pTree)
	{
		cout << "�ȴ����������������";
		return;
	}
	pTree->PreOrderTraverse((pTree->T));
}
void CTreeMenu::OnInOrderTraverse()
{
	if (!pTree)
	{
		cout << "�ȴ����������������";
		return;
	}
	pTree->InOrderTraverse((pTree->T));
}
void CTreeMenu::OnPostOrderTraverse()
{
	if (!pTree)
	{
		cout << "�ȴ��������ܺ������";
		return;
	}
	pTree->PostOrderTraverse((pTree->T));
}
void CTreeMenu::OnHuffmanCoding()
{
	cout << "�����������";
	cin >> z;

	cout << "����������Ȩ��";
	for (int q = 0; q<z; q++)
		cin >> a[q];
	pTree->HuffmanCoding(a, z, s);
	cout << "�շ����������";
}
void CTreeMenu::OnHuffmanShow()
{
	for (int i = 1; i <= z; ++i)
	{
		cout << "��" << i << "���ַ��ı���Ϊ";
		cout << (s[i]) << endl;
	}
}
void CListMenu::OnCreateList() {
	if (pList) {
		cout << "�����Ѵ���\n";
		return;
	}
	pList = new LinkList;
	cout << "�������ɹ�\n";
}

void CListMenu::OnListInsert() {
	if (!pList) {
		cout << "�����ȴ���������ܲ���Ԫ��\n";
		return;
	}
	cout << "����Ҫ���������";
	int a;
	cin >> a;
	if (pList->Insert(1, a) == OK)
		cout << "����ɹ�\n";
	else
		cout << "����ʧ��\n";
}
void CListMenu::OnListFind() {
	if (!pList)
	{
		cout << "�����ȴ���������ܲ���Ԫ��\n";
		return;
	}
	cout << "����ҪѰ�ҵ�������λ��";
	int a, e;
	cin >> a;
	if (pList->GetElem(a, e) == OK)
		cout << "���ҳɹ����ô���ֵΪ:" << e << "\n";
	else
		cout << "����ʧ��\n";
}
void CListMenu::OnListDelete() {
	if (!pList) {
		cout << "�����ȴ�����������Ԫ��" << endl;
		return;
	}
	cout << "����Ҫɾ����Ԫ�ص�λ��";
	int a;
	int b;
	cin >> a;
	if (pList->Delete(a, b) == OK)
		cout << "ɾ��Ԫ��" << b << endl;
	else
		cout << "ɾ��ʧ��\n";
}
void CListMenu::OnListShow() {
	if (!pList) {
		cout << "û�д�����\n";
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
	
	cout<<"������n";
	cin >> n;
	a = new int[n];
	for (int i = 0; i <n; i++) {
		cin >> a[i];
	}
	cout << "��ѡ������" << endl;

}