#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include "../../ch2/ch2/uniquearray.h"  //队列定义
#ifndef GRAPH
#define GRAPH


/*图的表示*/

#define max 10
typedef struct ArcCell  //ArcCell为矩阵的每个元素
{
	int ajd;  //边的权值
	char* info;  //边的信息
}ArcCell, AdjMatrix[max][max];

//图的表示
typedef struct Mgraph //图的表示
{
	char vertex[max];  //图的顶点表示
	AdjMatrix arcs;  //图的邻接矩阵
	int vexnum, arcnum;  //图的顶点数、边数
}Mgraph;

//在这里定义下面使用的图结构
//每个顶点以1到nvertices之间不重复的数作为标志

typedef struct edgenode
{
	int y;   //邻接点信息
	int weight;  //边的权值
	edgenode* next;  //下一条邻接边
}edgenode;  //链表结点


typedef struct graph
{
	edgenode* edge[max + 1];  //链表头指针数组
	int degree[max + 1];  //每个顶点的出度数组
	int nvertices;  //顶点数
	int nedges;  //边数
	bool directed;  //有向图
}graph;

//初始化图的存储结构
void initialize_graph(graph* g, bool directed)
{
	int i;
	g->nvertices = 0;  //点
	g->nedges = 0;  //边
	g->directed = directed;
	for (i = 1; i <= max; i++)
	{
		g->edge[i] = NULL;
		g->degree[i] = 0;
	}
}

//在邻接表的表首插入表结点，若是无向图需要两处插入
void insert_edge(graph* g, int x, int y, bool directed)
{
	//x为弧尾，y为弧头
	edgenode* p;
	p = (edgenode*)malloc(sizeof(edgenode));
	p->weight = 0;
	p->y = y;
	p->next = g->edge[x];  //接向现有的x的弧链表
	g->edge[x] = p;  //表首插入
	g->degree[x]++;
	if (directed == false)
	{
		insert_edge(g, y, x, true);
	}
	g->nedges++;
}

//图的存储结构建立
void read_graph(graph* g, bool directed)
{
	//第一行为图的顶点数和边数，以后顶点对表示的每条边
	int i, m, x, y;
	initialize_graph(g, directed);
	printf("please input the number of nodes and edges:\n");
	scanf_s("%d %d", &(g->nvertices),&m);  //输入顶点数，边数
	printf("please input the nodes of edges:\n");
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &x, &y);
		insert_edge(g, x, y, directed);  //插入到链表中
	}
}

/*图的遍历*/
bool discovered[max + 1];  //已发现顶点
bool processed[max + 1];  //已处理完结点
int parent[max + 1]; //遍历中形成的父子关系

void initialize_search(graph* g)
{
	//图遍历前，初始化
	int i;
	for (i = 1; i <= g->nvertices; i++)
	{
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

//广度优先搜索
void bfs(graph* g, int start)
{
	Queue q;
	int x, y;
	edgenode* p;
	
}
#endif // !GRAPH
