#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include "../../ch2/ch2/uniquearray.h"  //���ж���
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

//�����������
void bfs(graph* g, int start)
{
	Queue q;
	int x, y;
	edgenode* p;
	
}
#endif // !GRAPH
