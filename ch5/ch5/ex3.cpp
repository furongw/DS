#include <stdio.h>
#include "graph.h"

//dfs
void dfs(graph* g, int v)
{
	edgenode* p;
	int y;
	discovered[v] = true;
	p = g->edge[v];
	while (p != NULL)
	{
		y = p->y;
		if (discovered[y] == false)
		{
			dfs(g, y);
		}
		p = p->next;
	}
}

bool conected(graph* g)
{
	//ѡ��һ����ʼ��������ȱ���ͼ
	dfs(g, 1);
	//����discoverd��������н��δ�����֣�������ͨͼ
	int i;
	for (i = 1; i <= g->nvertices; i++)
	{
		if (!discovered[i])
		{
			printf("not connected");
			return false;
		}
	}
	printf("connected");
	return true;
}

int main()
{
	graph gra;
	graph* g = &gra;
	read_graph(g, true);
	conected(g);
}
