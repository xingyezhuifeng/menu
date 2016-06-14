#pragma once
#include "def.h"
#include <iostream>
using namespace std;
#define MAXSIZE 20
class Sort
{
private:
	double*a;
public:
	Sort(int * a, int n);
	Sort();
	void sort();
	void Insert(int*a, int n);
	void ShellSort(int* pDataArray, int iDataNum);
	void QuickSort(int *a, int left, int righ);
	void BublleSort(int *a, int n);
	

};