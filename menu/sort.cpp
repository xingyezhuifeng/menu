#include "StdAfx.h"
#include <iostream>
#include "sort.h"
using namespace std;
Sort::Sort(int *a, int n) {
	n =10;
	int i = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
}
Sort::Sort()
{
	delete[]a;
}
void Sort::sort()
{
}
void swap(int *a, int * b)//交换两个数
{
	int x;
	x = *a;
	*a = *b;
	*b = x;
}
void Sort::Insert(int*a,int n) {
	int i;
	int j;
	for (i = 2; i <= n; i++)
	{
		if (a[i] < a[i - 1])
		{
			a[0] = a[i];
			a[i] = a[i - 1];
			for (j = i - 2; a[0] < a[j]; j--)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = a[0];
		}
	}
}
void shellInsert(int* pDataArray, int d, int iDataNum){
	int i, j,temp;
	for (i = d; i < iDataNum; i += 1)    //从第2个数据开始插入
	{
		j = i - d;
		temp = pDataArray[i];    //记录要插入的数据
		while (j >= 0 && pDataArray[j] > temp)    //从后向前，找到比其小的数的位置
		{
			pDataArray[j + d] = pDataArray[j];    //向后挪动
			j -= d;
		}

		if (j != i - d)    //存在比其小的数
			pDataArray[j + d] = temp;
	}
}
void Sort::ShellSort(int* pDataArray, int iDataNum)
{
	int d;
	d = iDataNum / 2;    //初始增量设为数组长度的一半
	while (d >= 1)
	{
		shellInsert(pDataArray, d, iDataNum);
		d = d / 2;    //每次增量变为上次的二分之一
	}
}
void Sort::QuickSort(int *a, int left, int right) {
	int i = left;
	int j = right;
	int temp = a[left];
	if (left >= right)
		return;
	while (i != j)
	{
		while (i<j&&a[j] >= temp)
			j--;
		if (j>i)
			a[i] = a[j];//a[i]已经赋值给temp,所以直接将a[j]赋值给a[i],赋值完之后a[j],有空位
		while (i<j&&a[i] <= temp)
			i++;
		if (i<j)
			a[j] = a[i];
	}
	a[i] = temp;//把基准插入,此时i与j已经相等R[low..pivotpos-1].keys≤R[pivotpos].key≤R[pivotpos+1..high].keys
	QuickSort(a, left, i - 1);/*递归左边*/
	QuickSort(a, i + 1, right);/*递归右边*/
}
void Sort::BublleSort(int *a, int n) {
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 2; j <= n - i; j++)
			if (a[j - 1] > a[j])
			{
				a[0] = a[j];
				a[j] = a[j - 1];
				a[j - 1] = a[0];

			}
}
