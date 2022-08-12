#pragma once
#include"stdc++.h"
using namespace std;
typedef struct List {
	int data;
	struct List *next;
}List;

List* CreateList(vector<int>a) {
	List *list = new List;
	List *head = list;
	for (int i : a) {
		List *a = (List*)malloc(sizeof(List));//指向 新的内存空间
		a->data = i;//赋值
		head->next = a;//head 的 next指针 指向上一步 新的内存空间
		head = a; //使 新的内存空间成为 head
	}
	head->next=NULL;
	return list;
}
void CreateList(vector<int>a, DNode* head) {
	DNode *L = head;
	for (int i : a) {
		DNode *p = (DNode *)malloc(sizeof(DNode));
		p->data = i;
		p->llink = L;
		L->rlink = p;
		L = L->rlink;
	}
	head->len = a.size();
	L->rlink = NULL;
}
