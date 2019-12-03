#include <stdio.h>
#include "graph.h"

void nfs(graph* g, int v)
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
		printf("%d ", v);
		processed[v] = true;  //标记点v已处理
		p = g->edge[v];  //取v的第一个邻接点
		while (p != NULL)
		{
			y = p->y;
			if (discovered[y] == false)  //如果y未被发现
			{
				//入队，修改发现情况
				Queue_EnQueue(q, y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;  //取v的下一个邻接点
		}
	}
}

int main()
{
	graph gra;
	graph *g = &gra;
	read_graph(g, true);
	nfs(g, 1);
}