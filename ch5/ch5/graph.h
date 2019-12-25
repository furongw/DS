#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include "../../ch2/ch2/uniquearray.h"  //队列定义
#include "../../ch1/ch1/all.h"
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

//顶点处理函数，自定义
void process_vertex_early(int vertex)  
{
	printf("\nprocessing...");
	printf("vertex %d\n", vertex);
}

//边处理函数，自定义
void process_edge(int x, int y)
{
	printf("\n%d-->%d\n", x, y);
}

//顶点处理后函数
void process_vertex_late(int v)
{
	printf("\nvertex %d has been processed\n", v);
}

//广度优先搜索
void bfs(graph* g, int v)
{
	QueuePtr q;
	int x, y;
	edgenode* p;
	Queue_Init(&q);  //初始化一个队列
	Queue_EnQueue(q, v);  //起始点入队
	discovered[v] = true;  //将起始点加入已发现列表

	while (Queue_Empty(q) == false)  //队列不空
	{
		Queue_DeQueue(q, &v);  //取队首元素
		process_vertex_early(v);  //进入顶点时处理函数
		processed[v] = true;  //标记点v已处理
		p = g->edge[v];  //取v的第一个邻接点
		while (p != NULL)
		{
			y = p->y;
			if (processed[y] == false)
			{
				process_edge(v, y);
			}
			if (discovered[y] == false)  //如果y未被发现
			{
				//入队，修改发现情况
				Queue_EnQueue(q, y);  
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;  //取v的下一个邻接点
		}
		process_vertex_late(v);
	}
}

/*深度优先搜索*/
//简洁版
void dfs_simple(graph* g, int v)
{
	edgenode* p;
	int y;
	discovered[v] = true;
	process_vertex_early(v);  //开始处理v
	p = g->edge[v];
	while (p != NULL)
	{
		y = p->y;
		if (discovered[y] == false)
		{
			dfs_simple(g, y);
		}
		p = p->next;
	}
	process_vertex_late(v);  //处理完v以及其子图
}

//增强版
//引入两个数组，记录结点的进入时间和离开时间
int entry_time[max + 1] = { 0 };
int exit_time[max + 1] = { 0 };
void dfs_complex(graph* g, int v)
{
	int time = 0;
	edgenode* p;
	int y;
	time++;
	discovered[v] = true;
	entry_time[v] = time;
	process_vertex_early(v);
	p = g->edge[v];
	while (p != NULL)
	{
		y = p->y;
		if (discovered[y] == false)  //如果没有发现y
		{
			parent[y] = v;
			process_edge(v, y);
			dfs_complex(g, y);
		}
		else if (!processed[y])  //如果y未处理完
		{
			process_edge(v, y);
		}
		p = p->next;
	}
	process_vertex_late(v);
	time++;
	exit_time[v] = time;
	processed[v] = true;
}

//一个遍历所有连通分支的方法
void travergraph(graph* g)
{
	int i;
	initialize_search(g);
	for (i = 1; i <= g->nvertices; i++)
	{
		if (discovered[i] == false)
		{
			dfs_complex(g, i);
		}
	}
}

#endif // !GRAPH
