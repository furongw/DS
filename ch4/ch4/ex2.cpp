#include <stdio.h>
#include "tree.h"

#define TREESIZE 5

//练习2，以双亲表示法作树的存储结构，并求给定的树的深度的算法
int finddepth(PTree ptree, int now,int *depth)
{
	int nowparent,nowdata;
	nowparent = ptree.nodes[now].parent;
	if (nowparent == -1)  //如果没有双亲
	{
		return 0;
	}
	else
	{
		if (depth[nowparent])
			return 1 + depth[nowparent];
		else return finddepth(ptree, nowparent, depth)+1;  //如果有双亲，递归查找,深度等于双亲的深度加1
	}
}

int treedepth(PTree ptree, int* depth)
{
	int i;
	int max = 0;
	for (i = 0; i < TREESIZE; i++)
	{
		depth[i] = finddepth(ptree, i, depth);
		if (depth[i] > max)
		{
			max = depth[i];
		}
	}


	return max;
}

int main()
{
	PTree pttree;
	int i;
	int depth[TREESIZE] = { 0 };
	//写一个简单的测试
	pttree.nodes[0].parent = -1;
	pttree.nodes[1].parent = 0;
	pttree.nodes[2].parent = 0;
	pttree.nodes[3].parent = 2;
	pttree.nodes[4].parent = 3;
	printf("the depth of the tree is : %d", treedepth(pttree, depth));
}