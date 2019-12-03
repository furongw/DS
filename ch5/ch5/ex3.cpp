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
	//选择一个起始点深度优先遍历图
	dfs(g, 1);
	//遍历discoverd数组如果有结点未被发现，则不是连通图
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
