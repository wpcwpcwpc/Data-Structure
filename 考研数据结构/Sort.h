#pragma once
#include"stdc++.h"
using namespace std;
void Print(vector<int>a) { for (int i : a)cout << i << " "; cout << endl; }
//插入排序:
//直接插入排序
void InsertSort(vector<int>&a) {
	int i,j,mid;
	for (i = 1; i < a.size(); i++) {
		if (a[i] < a[i - 1]) {
			mid = a[i];
			for (j = i - 1; j >= 0&&mid < a[j]; j--)
				a[j + 1] = a[j];
			a[j + 1] = mid;
		}
	}
}

//快速排序 声明
void QuickSort(vector<int>&a,int low,int high);
int Partion(vector<int>&a, int low, int high);



//快速排序 定义
void QuickSort(vector<int>&a, int low, int high) {
	if (low < high) {
		int site = Partion(a, low, high);

		QuickSort(a, low, site - 1);

		QuickSort(a, site + 1, high);
	}
}
int  Partion(vector<int>&a, int low, int high) {
	int k = a[low];
	while (low < high) {
		while (low<high&&a[high]>k) --high;
		if (low < high) a[low++] = a[high];
		while (low < high&&a[low] < k)++low;
		if (low < high)a[high--] = a[low];
	}
	a[low] = k;
	return low;
}
