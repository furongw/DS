#include <stdio.h>
#include "graph.h"

void nfs(graph* g, int v)
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
		printf("%d ", v);
		processed[v] = true;  //��ǵ�v�Ѵ���
		p = g->edge[v];  //ȡv�ĵ�һ���ڽӵ�
		while (p != NULL)
		{
			y = p->y;
			if (discovered[y] == false)  //���yδ������
			{
				//��ӣ��޸ķ������
				Queue_EnQueue(q, y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;  //ȡv����һ���ڽӵ�
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