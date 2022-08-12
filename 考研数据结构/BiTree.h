#include"stdc++.h"
using namespace std;
typedef int ElemType;
#define Max 10
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;
BiTree PreCreateTree();
BiTree PreCreateTree() {
	BiTree T;
	ElemType item;
	cin >> item;
	if (item == 0)              //Ҷ�ڵ����ݱ�־����������0 
		T = NULL;            //��ĳһ�ڵ�ΪҶ�ӽ�㣬��������������ΪNULL��0��ʾ������
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = item;

		T->lchild = PreCreateTree();          //�ݹ鴴���������� 
		T->rchild = PreCreateTree();            //�ݹ鴴���������� 
	}
	return T;                              //���ظ��ڵ� 
}
//��������ݹ���
void PreOrder(BiTree T) {
	if (T != NULL) {
		cout << T->data<<" ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//��������ǵݹ�:ģ����*
void PreOrder(BiTree T, stack<BiTree>&S) {
	BiTree t = T;
	if (t != NULL)
		S.push(t);
	while (!S.empty())
	{
		BiTree t = S.top();
		cout << t->data << " ";
		S.pop();
		if (t->rchild != NULL)S.push(t->rchild);
		if (t->lchild != NULL)S.push(t->lchild);
	}
}

//��������ݹ���
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		cout << T->data<<" ";
		InOrder(T->rchild);
	}
}
//��������ǵݹ���:ģ����**
void InOrder(BiTree T, stack<BiTree>S) {
	if (T != NULL)
		S.push(T);
	BiTree t = T;
	while (t!= NULL||!S.empty()) {
		if (t != NULL) {
			S.push(t);
			t = t->lchild;
		}
		else {
			t = S.top();
			S.pop();
			cout << t->data << " ";
			t = t->rchild;
		}
	}
}

//��������ݹ���
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
}
//��������ǵݹ���:ģ����***
void PostOrder(BiTree T,stack<BiTree>&S) {
	BiTree t=T;
	BiTree R = NULL;
	while (t != NULL || !S.empty()) {
		if (t != NULL) {
			S.push(t);
			t = t->lchild;
		}
		else {//tΪ�գ������нڵ�û������
			t = S.top();
			if (t->rchild != NULL&&t->rchild!=R) {//ģ���㣬������Ϊ���ж��Ƿ�����������صģ������ظ�
				//t������������ǰ�����ʲ���������������������û�����ʹ���������������������
				t = t->rchild;
				S.push(t);
				t = t->lchild;
			}
			else {
				S.pop();
				cout << t->data << " ";
				R = t;//ģ���㣬��¼ǰ����Ϊ��֮����жϷ��ط�����ж�����
				t = NULL;//ģ���㣬����t
			}
		}
	}
}

//��α���:ģ����*
void LevelOrder(BiTree T,queue<BiTree>&Q) {
	//�ö��е�FIFO���ص㣬�������²�α�����ÿ��һ���ڵ㽫������������
	BiTree t;
	if (T != NULL)
		Q.push(T);
	while (!Q.empty()) {
		t = Q.front();
		Q.pop();
		cout << t->data<<" ";
		if (T->lchild != NULL)Q.push(t->lchild);
		if (T->rchild != NULL)Q.push(t->rchild);
	}
}

////�ǵݹ鷨�ж��Ƿ�����ȫ������
bool Is_TotalTree(BiTree T) {
	queue<BiTree>q;
	q.push(T);
	int i = 1;
	while (!q.empty()) {
		BiTree N = q.front();
		q.pop();
		if (N != NULL) {
			q.push(N->lchild);
			q.push(N->rchild);
		}
		else {
			while (!q.empty()) {
				BiTree N = q.front();
				q.pop();
				if (N)
					return 0;
			}
		}
	}
	return 1;
}

//ͳ�����Ľڵ����
int Count_Node(BiTree T) {
	int sum = 1;
	if (T->lchild != NULL)
		sum += Count_Node(T->lchild);
	if (T->rchild != NULL)
		sum += Count_Node(T->rchild);
	return sum;
}












