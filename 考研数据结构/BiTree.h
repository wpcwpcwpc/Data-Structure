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
	if (item == 0)              //叶节点数据标志：其后根两个0 
		T = NULL;            //若某一节点为叶子结点，则其左右子树均为NULL，0表示建空树
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = item;

		T->lchild = PreCreateTree();          //递归创建其左子树 
		T->rchild = PreCreateTree();            //递归创建其右子树 
	}
	return T;                              //返回根节点 
}
//先序遍历递归型
void PreOrder(BiTree T) {
	if (T != NULL) {
		cout << T->data<<" ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//先序遍历非递归:模糊性*
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

//中序遍历递归型
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		cout << T->data<<" ";
		InOrder(T->rchild);
	}
}
//中序遍历非递归型:模糊性**
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

//后序遍历递归型
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
}
//后序遍历非递归型:模糊性***
void PostOrder(BiTree T,stack<BiTree>&S) {
	BiTree t=T;
	BiTree R = NULL;
	while (t != NULL || !S.empty()) {
		if (t != NULL) {
			S.push(t);
			t = t->lchild;
		}
		else {//t为空，但还有节点没被访问
			t = S.top();
			if (t->rchild != NULL&&t->rchild!=R) {//模糊点，条件是为了判定是否从右子树返回的，避免重复
				//t右子树不空且前驱访问不是其右子树，即右子树没被访问过，跳过根访问其右子树
				t = t->rchild;
				S.push(t);
				t = t->lchild;
			}
			else {
				S.pop();
				cout << t->data << " ";
				R = t;//模糊点，记录前驱，为了之后的判断返回方向的判定条件
				t = NULL;//模糊点，重置t
			}
		}
	}
}

//层次遍历:模糊性*
void LevelOrder(BiTree T,queue<BiTree>&Q) {
	//用队列的FIFO的特点，从上往下层次遍历，每读一个节点将左右子树进队
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

////非递归法判断是否是完全二叉树
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

//统计树的节点个数
int Count_Node(BiTree T) {
	int sum = 1;
	if (T->lchild != NULL)
		sum += Count_Node(T->lchild);
	if (T->rchild != NULL)
		sum += Count_Node(T->rchild);
	return sum;
}












