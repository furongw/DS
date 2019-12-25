#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include "../../ch2/ch2/uniquearray.h"  //���ж���
#include "../../ch1/ch1/all.h"
#ifndef GRAPH
#define GRAPH


/*ͼ�ı�ʾ*/

#define max 10
typedef struct ArcCell  //ArcCellΪ�����ÿ��Ԫ��
{
	int ajd;  //�ߵ�Ȩֵ
	char* info;  //�ߵ���Ϣ
}ArcCell, AdjMatrix[max][max];

//ͼ�ı�ʾ
typedef struct Mgraph //ͼ�ı�ʾ
{
	char vertex[max];  //ͼ�Ķ����ʾ
	AdjMatrix arcs;  //ͼ���ڽӾ���
	int vexnum, arcnum;  //ͼ�Ķ�����������
}Mgraph;

//�����ﶨ������ʹ�õ�ͼ�ṹ
//ÿ��������1��nvertices֮�䲻�ظ�������Ϊ��־

typedef struct edgenode
{
	int y;   //�ڽӵ���Ϣ
	int weight;  //�ߵ�Ȩֵ
	edgenode* next;  //��һ���ڽӱ�
}edgenode;  //������


typedef struct graph
{
	edgenode* edge[max + 1];  //����ͷָ������
	int degree[max + 1];  //ÿ������ĳ�������
	int nvertices;  //������
	int nedges;  //����
	bool directed;  //����ͼ
}graph;

//��ʼ��ͼ�Ĵ洢�ṹ
void initialize_graph(graph* g, bool directed)
{
	int i;
	g->nvertices = 0;  //��
	g->nedges = 0;  //��
	g->directed = directed;
	for (i = 1; i <= max; i++)
	{
		g->edge[i] = NULL;
		g->degree[i] = 0;
	}
}

//���ڽӱ�ı��ײ�����㣬��������ͼ��Ҫ��������
void insert_edge(graph* g, int x, int y, bool directed)
{
	//xΪ��β��yΪ��ͷ
	edgenode* p;
	p = (edgenode*)malloc(sizeof(edgenode));
	p->weight = 0;
	p->y = y;
	p->next = g->edge[x];  //�������е�x�Ļ�����
	g->edge[x] = p;  //���ײ���
	g->degree[x]++;
	if (directed == false)
	{
		insert_edge(g, y, x, true);
	}
	g->nedges++;
}

//ͼ�Ĵ洢�ṹ����
void read_graph(graph* g, bool directed)
{
	//��һ��Ϊͼ�Ķ������ͱ������Ժ󶥵�Ա�ʾ��ÿ����
	int i, m, x, y;
	initialize_graph(g, directed);
	printf("please input the number of nodes and edges:\n");
	scanf_s("%d %d", &(g->nvertices),&m);  //���붥����������
	printf("please input the nodes of edges:\n");
	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &x, &y);
		insert_edge(g, x, y, directed);  //���뵽������
	}
}

/*ͼ�ı���*/
bool discovered[max + 1];  //�ѷ��ֶ���
bool processed[max + 1];  //�Ѵ�������
int parent[max + 1]; //�������γɵĸ��ӹ�ϵ

void initialize_search(graph* g)
{
	//ͼ����ǰ����ʼ��
	int i;
	for (i = 1; i <= g->nvertices; i++)
	{
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

//���㴦�������Զ���
void process_vertex_early(int vertex)  
{
	printf("\nprocessing...");
	printf("vertex %d\n", vertex);
}

//�ߴ��������Զ���
void process_edge(int x, int y)
{
	printf("\n%d-->%d\n", x, y);
}

//���㴦�����
void process_vertex_late(int v)
{
	printf("\nvertex %d has been processed\n", v);
}

//�����������
void bfs(graph* g, int v)
{
	QueuePtr q;
	int x, y;
	edgenode* p;
	Queue_Init(&q);  //��ʼ��һ������
	Queue_EnQueue(q, v);  //��ʼ�����
	discovered[v] = true;  //����ʼ������ѷ����б�

	while (Queue_Empty(q) == false)  //���в���
	{
		Queue_DeQueue(q, &v);  //ȡ����Ԫ��
		process_vertex_early(v);  //���붥��ʱ������
		processed[v] = true;  //��ǵ�v�Ѵ���
		p = g->edge[v];  //ȡv�ĵ�һ���ڽӵ�
		while (p != NULL)
		{
			y = p->y;
			if (processed[y] == false)
			{
				process_edge(v, y);
			}
			if (discovered[y] == false)  //���yδ������
			{
				//��ӣ��޸ķ������
				Queue_EnQueue(q, y);  
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;  //ȡv����һ���ڽӵ�
		}
		process_vertex_late(v);
	}
}

/*�����������*/
//����
void dfs_simple(graph* g, int v)
{
	edgenode* p;
	int y;
	discovered[v] = true;
	process_vertex_early(v);  //��ʼ����v
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
	process_vertex_late(v);  //������v�Լ�����ͼ
}

//��ǿ��
//�����������飬��¼���Ľ���ʱ����뿪ʱ��
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
		if (discovered[y] == false)  //���û�з���y
		{
			parent[y] = v;
			process_edge(v, y);
			dfs_complex(g, y);
		}
		else if (!processed[y])  //���yδ������
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

//һ������������ͨ��֧�ķ���
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
