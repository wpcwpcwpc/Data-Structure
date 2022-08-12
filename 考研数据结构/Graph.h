#pragma once
#include"stdc++.h"
using namespace std;
#define VerNum 10
typedef int VertexType;				//顶点的数据类型
typedef int EdgeType;				//边上权值的数据类型 
typedef int InfoType;				//网的边权值数据类型
//邻接矩阵存储
typedef struct MArcNode{			//邻接表边的权值
	InfoType info;
}MArcNode;
typedef struct MVerNode{			//顶点数据
	VertexType adj;
}MVerNode;			
//邻接矩阵ADT;
typedef struct MGraph {
	MVerNode Vex[VerNum];			//顶点表
	MArcNode Edge[VerNum][VerNum];	//邻接矩阵，边表
	int vexnum;						//图的当前顶点数
	int arcnum;						//图的当前弧数
}MGraph;

//邻接表存储
typedef struct ArcNode {			//边表节点
	int adjvex;						//该弧指向顶点的位置序号
	VertexType data;				//该弧指向顶点的顶点信息
	struct ArcNode *next;			//指向下一条弧的指针
	InfoType info;					//网的边权值
}ArcNode;
typedef struct VNode {				//顶点表节点
	VertexType	data;				//顶点信息
	ArcNode *first;					//指向第一条依附该顶点的弧的指针	
}VNode,AdjList[VerNum];
typedef struct ALGraph
{
	AdjList vertices;				//邻接表
	int vexnum;				//图的当前顶点数
	int arcnum;				//图的当前弧数
}ALGraph;


//邻接矩阵求顶点的位置
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
//邻接表求顶点位置
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

//邻接矩阵创建  无向图
void CreateGraph(MGraph &G)
{
	int i, k, j;
	VertexType v1, v2;
	cout << "用邻接矩阵来创建图 请输入图的顶点个数和弧数\n";
	cin>>G.vexnum>>G.arcnum;
	for (i = 0; i<G.vexnum; i++)
		for (j = 0; j<G.vexnum; j++)
			G.Edge[i][j].info = 0;  //初始化邻接矩阵
	printf("请输入图的各个顶点\n");
	for (i = 0; i<G.vexnum; i++)
		cin>>G.Vex[i].adj; //输入图的各个顶点

	cout<<"请输入两个顶点之间的弧 一行两个顶点用，隔开\n";
	
	for (k = 0; k<G.arcnum; k++){
		cin>>v1>>v2;
		i = MLocateVertex(G, v1);
		j = MLocateVertex(G, v2);
		G.Edge[i][j].info = 1;
		G.Edge[j][i].info= 1;
	}
	printf("打印出用邻接矩阵创建的无向图\n");
	for (i = 0; i<G.vexnum; i++){
		for (j = 0; j < G.vexnum; j++)
			cout<<G.Edge[i][j].info<<" ";
		cout << endl;
	}
}
//邻接矩阵创建  有向带权图
void Create_Aim_Graph(MGraph &G)
{
	int i, k, j;
	VertexType v1, v2;
	InfoType inf;
	cout << "用邻接矩阵来创建图 请输入图的顶点个数和弧数\n";
	cin >> G.vexnum >> G.arcnum;
	for (i = 0; i<G.vexnum; i++)
		for (j = 0; j<G.vexnum; j++)
			G.Edge[i][j].info = 0;  //初始化邻接矩阵
	printf("请输入图的各个顶点\n");
	for (i = 0; i<G.vexnum; i++)
		cin >> G.Vex[i].adj; //输入图的各个顶点

	cout << "请输入两个顶点之间的弧及权值，一行两个顶点用 隔开\n";

	for (k = 0; k<G.arcnum; k++) {
		cin >> v1 >> v2 >> inf;
		i = MLocateVertex(G, v1);
		j = MLocateVertex(G, v2);
		G.Edge[i][j].info = inf;
	}
	printf("打印出用邻接矩阵创建的无向图\n");
	for (i = 0; i<G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++)
			cout << G.Edge[i][j].info << " ";
		cout << endl;
	}
}


//邻接表创建  无向图
void CreateList(ALGraph &G) //用邻接表创建无向图
{
	int i;
	printf("用邻接表来创建图 请输入图的顶点个数和弧数\n");
	cin>>G.vexnum>>G.arcnum;
	printf("请输入图的各个顶点\n");
	getchar();
	for (i = 0; i<G.vexnum; i++)
	{
		cin>>G.vertices[i].data; //输入图的各个顶点
		G.vertices[i].first = NULL;
	}
	printf("请输入弧两端的序号顶点\n");
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
		temp->next = G.vertices[i].first; //前插法
		G.vertices[i].first = temp;
		
		ArcNode *temp1 = (ArcNode *)malloc(sizeof(ArcNode));
		temp1->adjvex = i;
		temp1->data = a1;
		temp1->next = G.vertices[j].first;
		G.vertices[j].first = temp1;
	}
	
}
//邻接表创建  有向图
void CreateGraph(ALGraph &G) //用邻接表创建无向图
{
	int i;
	printf("用邻接表来创建图 请输入图的顶点个数和弧数\n");
	cin >> G.vexnum >> G.arcnum;
	printf("请输入图的各个顶点\n");
	getchar();
	for (i = 0; i<G.vexnum; i++)
	{
		cin >> G.vertices[i].data; //输入图的各个顶点
		G.vertices[i].first = NULL;
	}
	printf("请输入弧两端的序号顶点\n");
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
		temp->next = G.vertices[i].first; //前插法
		G.vertices[i].first = temp;
	}

}

void PrintAG(ALGraph &G)  //打印邻接表建立的图
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

//邻接表广度优先搜索
queue<VNode>BFSQue;
vector<bool>BFSVisit(0);
vector<int>_LPath(0);
void BFS(ALGraph G, int v) {
	//_LPath.resize(G.vexnum);//用于记录一点到所有点的最短路径，
							  //这里默认从G.vertices[0]开始的，可根据题目要求修改参数
	cout << G.vertices[v].data << endl;//访问当前节点
	BFSVisit[v] = true;//“染色”表示已访问
	BFSQue.push(G.vertices[v]);//将当前节点进队，进入遍历循环
	while (!BFSQue.empty()) {
		VNode N = BFSQue.front();//获取最先进队的顶点，并出队
		BFSQue.pop();
		for (ArcNode *w = N.first; w != NULL; w = w->next)//访问N的所有邻接节点
			if (!BFSVisit[w->adjvex]) { //MayBe Error
				BFSVisit[w->adjvex] = true;//同上
				/*//用于求单源最短路径的算法添加如下
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

//邻接表深度优先搜索
vector<bool>DFSVisit(0);
void DFS(ALGraph G,int v) {
	//cout << G.vertices[v].data;//根据需要加代码
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

//拓扑排序，提前传入indegree入度数组
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




