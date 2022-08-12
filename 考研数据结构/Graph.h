#pragma once
#include"stdc++.h"
using namespace std;
#define VerNum 10
typedef int VertexType;				//�������������
typedef int EdgeType;				//����Ȩֵ���������� 
typedef int InfoType;				//���ı�Ȩֵ��������
//�ڽӾ���洢
typedef struct MArcNode{			//�ڽӱ�ߵ�Ȩֵ
	InfoType info;
}MArcNode;
typedef struct MVerNode{			//��������
	VertexType adj;
}MVerNode;			
//�ڽӾ���ADT;
typedef struct MGraph {
	MVerNode Vex[VerNum];			//�����
	MArcNode Edge[VerNum][VerNum];	//�ڽӾ��󣬱߱�
	int vexnum;						//ͼ�ĵ�ǰ������
	int arcnum;						//ͼ�ĵ�ǰ����
}MGraph;

//�ڽӱ�洢
typedef struct ArcNode {			//�߱�ڵ�
	int adjvex;						//�û�ָ�򶥵��λ�����
	VertexType data;				//�û�ָ�򶥵�Ķ�����Ϣ
	struct ArcNode *next;			//ָ����һ������ָ��
	InfoType info;					//���ı�Ȩֵ
}ArcNode;
typedef struct VNode {				//�����ڵ�
	VertexType	data;				//������Ϣ
	ArcNode *first;					//ָ���һ�������ö���Ļ���ָ��	
}VNode,AdjList[VerNum];
typedef struct ALGraph
{
	AdjList vertices;				//�ڽӱ�
	int vexnum;				//ͼ�ĵ�ǰ������
	int arcnum;				//ͼ�ĵ�ǰ����
}ALGraph;


//�ڽӾ����󶥵��λ��
int MLocateVertex(MGraph  &G, VertexType v) 
{
	int j = -1, k;
	for (k = 0; k<G.vexnum; k++)
		if (G.Vex[k].adj == v){
			j = k;
			break;
		}
	return (j);
}
//�ڽӱ��󶥵�λ��
int ALocateVertex(ALGraph  &G, VertexType v)
{
	int j = -1, k;
	for (k = 0; k<G.vexnum; k++)
		if (G.vertices[k].data == v) {
			j = k;
			break;
		}
	return j;
}

//�ڽӾ��󴴽�  ����ͼ
void CreateGraph(MGraph &G)
{
	int i, k, j;
	VertexType v1, v2;
	cout << "���ڽӾ���������ͼ ������ͼ�Ķ�������ͻ���\n";
	cin>>G.vexnum>>G.arcnum;
	for (i = 0; i<G.vexnum; i++)
		for (j = 0; j<G.vexnum; j++)
			G.Edge[i][j].info = 0;  //��ʼ���ڽӾ���
	printf("������ͼ�ĸ�������\n");
	for (i = 0; i<G.vexnum; i++)
		cin>>G.Vex[i].adj; //����ͼ�ĸ�������

	cout<<"��������������֮��Ļ� һ�����������ã�����\n";
	
	for (k = 0; k<G.arcnum; k++){
		cin>>v1>>v2;
		i = MLocateVertex(G, v1);
		j = MLocateVertex(G, v2);
		G.Edge[i][j].info = 1;
		G.Edge[j][i].info= 1;
	}
	printf("��ӡ�����ڽӾ��󴴽�������ͼ\n");
	for (i = 0; i<G.vexnum; i++){
		for (j = 0; j < G.vexnum; j++)
			cout<<G.Edge[i][j].info<<" ";
		cout << endl;
	}
}
//�ڽӾ��󴴽�  �����Ȩͼ
void Create_Aim_Graph(MGraph &G)
{
	int i, k, j;
	VertexType v1, v2;
	InfoType inf;
	cout << "���ڽӾ���������ͼ ������ͼ�Ķ�������ͻ���\n";
	cin >> G.vexnum >> G.arcnum;
	for (i = 0; i<G.vexnum; i++)
		for (j = 0; j<G.vexnum; j++)
			G.Edge[i][j].info = 0;  //��ʼ���ڽӾ���
	printf("������ͼ�ĸ�������\n");
	for (i = 0; i<G.vexnum; i++)
		cin >> G.Vex[i].adj; //����ͼ�ĸ�������

	cout << "��������������֮��Ļ���Ȩֵ��һ������������ ����\n";

	for (k = 0; k<G.arcnum; k++) {
		cin >> v1 >> v2 >> inf;
		i = MLocateVertex(G, v1);
		j = MLocateVertex(G, v2);
		G.Edge[i][j].info = inf;
	}
	printf("��ӡ�����ڽӾ��󴴽�������ͼ\n");
	for (i = 0; i<G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++)
			cout << G.Edge[i][j].info << " ";
		cout << endl;
	}
}


//�ڽӱ���  ����ͼ
void CreateList(ALGraph &G) //���ڽӱ�������ͼ
{
	int i;
	printf("���ڽӱ�������ͼ ������ͼ�Ķ�������ͻ���\n");
	cin>>G.vexnum>>G.arcnum;
	printf("������ͼ�ĸ�������\n");
	getchar();
	for (i = 0; i<G.vexnum; i++)
	{
		cin>>G.vertices[i].data; //����ͼ�ĸ�������
		G.vertices[i].first = NULL;
	}
	printf("�����뻡���˵���Ŷ���\n");
	VertexType a1, a2;
	for (i = 0; i<G.arcnum; i++)
	{
		VertexType  i, j;

		cin>>a1>>a2;
		
		j = ALocateVertex(G, a2);
		i = ALocateVertex(G, a1);
		
		ArcNode *temp = (ArcNode *)malloc(sizeof(ArcNode));
		temp->adjvex = j;
		temp->data = a2;
		temp->next = G.vertices[i].first; //ǰ�巨
		G.vertices[i].first = temp;
		
		ArcNode *temp1 = (ArcNode *)malloc(sizeof(ArcNode));
		temp1->adjvex = i;
		temp1->data = a1;
		temp1->next = G.vertices[j].first;
		G.vertices[j].first = temp1;
	}
	
}
//�ڽӱ���  ����ͼ
void CreateGraph(ALGraph &G) //���ڽӱ�������ͼ
{
	int i;
	printf("���ڽӱ�������ͼ ������ͼ�Ķ�������ͻ���\n");
	cin >> G.vexnum >> G.arcnum;
	printf("������ͼ�ĸ�������\n");
	getchar();
	for (i = 0; i<G.vexnum; i++)
	{
		cin >> G.vertices[i].data; //����ͼ�ĸ�������
		G.vertices[i].first = NULL;
	}
	printf("�����뻡���˵���Ŷ���\n");
	VertexType a1, a2;
	for (i = 0; i<G.arcnum; i++)
	{
		VertexType  i, j;

		cin >> a1 >> a2;

		j = ALocateVertex(G, a2);
		i = ALocateVertex(G, a1);

		ArcNode *temp = (ArcNode *)malloc(sizeof(ArcNode));
		temp->adjvex = j;
		temp->data = a2;
		temp->next = G.vertices[i].first; //ǰ�巨
		G.vertices[i].first = temp;
	}

}

void PrintAG(ALGraph &G)  //��ӡ�ڽӱ�����ͼ
{
	int i;
	for (i = 0; i<G.vexnum; i++)
	{
		cout<<G.vertices[i].data<<"---> ";
		ArcNode *t=G.vertices[i].first;
		while (t != NULL){
			
			cout<<G.vertices[ALocateVertex(G, t->adjvex)].data<<" ";
			t = t->next;
		}
		printf("\n");
	}
}

//�ڽӱ�����������
queue<VNode>BFSQue;
vector<bool>BFSVisit(0);
vector<int>_LPath(0);
void BFS(ALGraph G, int v) {
	//_LPath.resize(G.vexnum);//���ڼ�¼һ�㵽���е�����·����
							  //����Ĭ�ϴ�G.vertices[0]��ʼ�ģ��ɸ�����ĿҪ���޸Ĳ���
	cout << G.vertices[v].data << endl;//���ʵ�ǰ�ڵ�
	BFSVisit[v] = true;//��Ⱦɫ����ʾ�ѷ���
	BFSQue.push(G.vertices[v]);//����ǰ�ڵ���ӣ��������ѭ��
	while (!BFSQue.empty()) {
		VNode N = BFSQue.front();//��ȡ���Ƚ��ӵĶ��㣬������
		BFSQue.pop();
		for (ArcNode *w = N.first; w != NULL; w = w->next)//����N�������ڽӽڵ�
			if (!BFSVisit[w->adjvex]) { //MayBe Error
				BFSVisit[w->adjvex] = true;//ͬ��
				/*//������Դ���·�����㷨�������
				_LPath[w->adjvex] = _LPath[v] + 1;
				*/
				BFSQue.push(G.vertices[w->adjvex]);
			}
	}
}
void BFSTranvers(ALGraph G) {
	BFSVisit.resize(G.vexnum);
	for (int i = 0; i < G.vexnum; i++) {
		BFSVisit[i] = false;
		for (int j = 0; j < G.vexnum; j++) {
			if (!BFSVisit[j])
				BFS(G, j);
		}
	}
}
//BFS//

//�ڽӱ������������
vector<bool>DFSVisit(0);
void DFS(ALGraph G,int v) {
	//cout << G.vertices[v].data;//������Ҫ�Ӵ���
	DFSVisit[v] = true;
	for (ArcNode *w = G.vertices[v].first; w != NULL; w = w->next) {
		if (!DFSVisit[w->adjvex])
			DFS(G, w->adjvex);
	}
}
void DFSTranvers(ALGraph G){
	DFSVisit.resize(G.vexnum);
	for (int v = 0; v < G.vexnum; v++)DFSVisit[v] = false;
	for (int v = 0; v < G.vexnum; v++) {
		if (!DFSVisit[v])
			DFS(G, v);
	}
}

//����������ǰ����indegree�������
vector<int> ToplologicalSort(ALGraph G, vector<VertexType>indegree) {
	stack<VertexType>S;
	vector<VertexType>Pr;
	Pr.resize(indegree.size());
	for (int i = 0; i < G.vexnum; i++)
		if (indegree[i] == 0)
			S.push(i);
	int count = 0;
	VertexType i; 
	while (!S.empty())
	{
		i = S.top();
		S.pop();
		Pr[count++] =i;
		for (ArcNode* p = G.vertices[i].first; p != NULL; p = p->next) {
			VertexType v = p->adjvex;
			if (!(--indegree[v]))
				S.push(v);
		}
	}
		return Pr;
}

vector<vector<MArcNode> > Floyed(MGraph G) {
	vector<vector<MArcNode>>A(G.vexnum);
	for (int i = 0; i < G.vexnum;i++)A[i]=vector<MArcNode>(G.vexnum);

	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			A[i][j] = G.Edge[i][j];

	for (int k = 0; k < G.vexnum; k++)
		for (int i = 0; i < G.vexnum; i++)
			for (int j = 0; j < G.vexnum; j++)
				if (A[i][j].info>A[j][k].info + A[k][j].info)
					A[i][j].info = A[j][k].info + A[k][j].info;
	return A;
}




