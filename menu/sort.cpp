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
void swap(int *a, int * b)//����������
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
	for (i = d; i < iDataNum; i += 1)    //�ӵ�2�����ݿ�ʼ����
	{
		j = i - d;
		temp = pDataArray[i];    //��¼Ҫ���������
		while (j >= 0 && pDataArray[j] > temp)    //�Ӻ���ǰ���ҵ�����С������λ��
		{
			pDataArray[j + d] = pDataArray[j];    //���Ų��
			j -= d;
		}

		if (j != i - d)    //���ڱ���С����
			pDataArray[j + d] = temp;
	}
}
void Sort::ShellSort(int* pDataArray, int iDataNum)
{
	int d;
	d = iDataNum / 2;    //��ʼ������Ϊ���鳤�ȵ�һ��
	while (d >= 1)
	{
		shellInsert(pDataArray, d, iDataNum);
		d = d / 2;    //ÿ��������Ϊ�ϴεĶ���֮һ
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
			a[i] = a[j];//a[i]�Ѿ���ֵ��temp,����ֱ�ӽ�a[j]��ֵ��a[i],��ֵ��֮��a[j],�п�λ
		while (i<j&&a[i] <= temp)
			i++;
		if (i<j)
			a[j] = a[i];
	}
	a[i] = temp;//�ѻ�׼����,��ʱi��j�Ѿ����R[low..pivotpos-1].keys��R[pivotpos].key��R[pivotpos+1..high].keys
	QuickSort(a, left, i - 1);/*�ݹ����*/
	QuickSort(a, i + 1, right);/*�ݹ��ұ�*/
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
