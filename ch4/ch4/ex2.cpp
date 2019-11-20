#include <stdio.h>
#include "tree.h"

#define TREESIZE 5

//��ϰ2����˫�ױ�ʾ�������Ĵ洢�ṹ�����������������ȵ��㷨
int finddepth(PTree ptree, int now,int *depth)
{
	int nowparent,nowdata;
	nowparent = ptree.nodes[now].parent;
	if (nowparent == -1)  //���û��˫��
	{
		return 0;
	}
	else
	{
		if (depth[nowparent])
			return 1 + depth[nowparent];
		else return finddepth(ptree, nowparent, depth)+1;  //�����˫�ף��ݹ����,��ȵ���˫�׵���ȼ�1
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
	//дһ���򵥵Ĳ���
	pttree.nodes[0].parent = -1;
	pttree.nodes[1].parent = 0;
	pttree.nodes[2].parent = 0;
	pttree.nodes[3].parent = 2;
	pttree.nodes[4].parent = 3;
	printf("the depth of the tree is : %d", treedepth(pttree, depth));
}