#pragma once
#define ID_LIST 1
#define ID_STACK_QUEUE 2
#define ID_STR_ARR_GL 3
#define ID_TREE 4
#define ID_GRAPH 5
#define ID_SEARCH 6
#define ID_SORT 7
#define ID_EXIT 8

#define ID_CREATE_LIST 1
#define ID_LIST_INSERT 2
#define ID_LIST_FIND 3
#define ID_LIST_DELET 4
#define ID_LIST_SHOW 5
#define ID_LIST_RETURN 6
#define ID_SORT_BUBBLE 5
#define ID_SORT_INSERT 2
#define ID_SORT_QUICK 3
#define ID_SORT_SHELL 4
#define ID_SORT_SHOW 1
#define ID_SORT_RETURN 7
#define ID_SORT_QITA 6
#define ID_SORT_SELECT 1
#define ID_SORT_DUI 2
#define ID_CREATE_TREE 1
#define ID_PREORDER_TREE 2
#define ID_INORDER_TREE 3
#define ID_POSTORDER_TREE 4
#define ID_HUFFMAN_TREE 5
#define ID_HUFFMANCODE_TREE 6
#define ID_TREE_RETURN 7
#define SUBMENU(submenu)	pBase=new submenu(pBase);
#define EXIT_SUBMENU tmp=m_pParent;\
			delete pBase;\
			pBase=tmp;

void InvalidateAction();
