#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void cal_indegree(Mgraph* g)
{
	int i,j,count;
	//计算每一列之和
	for (i = 0; i < g->vexnum; i++)
	{
		count = 0;
		for (j = 0; j < g->vexnum; j++)
		{
			if (g->arcs[j][i].ajd)
			{
				count++;
			}
		}
		printf("the vex %c have %d indegree\n", g->vertex[i], count);
	}
}

void cal_outdegree(Mgraph* g)
{
	int i, j, count;
	//计算每一行之和
	for (i = 0; i < g->vexnum; i++)
	{
		count = 0;
		for (j = 0; j < g->vexnum; j++)
		{
			if (g->arcs[i][j].ajd)
			{
				count++;
			}
		}
		printf("the vex %c have %d outdegree\n", g->vertex[i], count);
	}
}

void most_outdegree(Mgraph* g)
{
	int i, j, count,maxcount = 0;
	int maxi = 0;  //最大出度结点编号
	//计算每一行之和
	for (i = 0; i < g->vexnum; i++)
	{
		count = 0;
		for (j = 0; j < g->vexnum; j++)
		{
			if (g->arcs[i][j].ajd)
			{
				count++;
			}
		}
		if (count > maxcount)
		{	
			maxcount = count;
			maxi = i;
		}
	}
	printf("the %d th vex %c have the most outdegree\n", maxi, g->vertex[maxi]);
}

int outdegree0(Mgraph* g)
{
	int i, j;
	int count = 0;  //无出度的结点个数
	//计算每一行之和
	for (i = 0; i < g->vexnum; i++)
	{
		for (j = 0; j < g->vexnum; j++)
		{
			if (g->arcs[i][j].ajd)
			{
				break;
			}
		}
		if (j == g->vexnum) count++;
	}
	printf("there are %d nodes have no outdegree", count);
	return count;
}

bool whetherij(Mgraph* g,int i,int j)
{
	return g->arcs[i][j].ajd;
}

int main()
{
	//init a graph
	Mgraph gra;
	Mgraph* g = &gra;
	g->vexnum = 4;
	int i, j;
	int edges[4][4]= { {0,1,1,0},{0,0,0,1},{0,0,0,0},{1,0,0,0} };
	char ver[4] = { 'a','b','c','d' };
	for (i = 0; i < g->vexnum; i++)
	{
		for (j = 0; j < g->vexnum; j++)
		{
			g->arcs[i][j].ajd = edges[i][j];
			
		}
		g->vertex[i] = ver[i];
	}
	
	int indegree;
	int *p = &indegree;
	//cal_indegree(g);
	//cal_outdegree(g);
	//most_outdegree(g);
	//outdegree0(g);
	printf("the edge %d to %d exit?: %d\n",1,4 ,whetherij(g, 1, 4));

	printf("the edge %d to %d exit?: %d\n",3,3 ,whetherij(g, 3, 3));
	
}