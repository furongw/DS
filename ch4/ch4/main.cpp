#include <stdio.h>
#include "tree.h"
#include <malloc.h>

#define nodenum 7  //���Ľ������
void visit(char ord[])
{
	printf("%s ", ord);
}

//Ϊ�˷�����֤�㷨��д��һ������������ʼ���ĺ���������ֵΪ���
void initfullbintree(BiTree *p,int layer,Datatype data)
{
	BiTree now;
	if (layer == 0)
	{
		*p = NULL;
		return;
	}
	else
	{
		*p = (BiTree)malloc(sizeof(BiTreeNode));
		now = *p;
		now->data = data;
		initfullbintree(&now->lchild,layer-1,2*data);
		initfullbintree(&now->rchild, layer - 1,2*data+1);
	}
}

int main()
{
	BiTreeNode node;
	BiTree p = &node;
	int i;
	
	//��ʼ��һ����������
	initfullbintree(&p, 4, 1);
	/*
	//���ֱ���
	printf("preorder:\n");
	PreOrder(p);
	printf("\ninorder:\n");
	InOrder(p);
	printf("\npostorder:\n");
	PostOrder(p);
	//�ǵݹ��������
	printf("\nnot recursion inorer:\n");
	NRInOrder(p);
	printf("\nLevelOrder:\n");
	LevelOrder(p);*/
	
	/*�������������������������һ�ö�����*/
	/*Datatype preord[] = { 1,2,3,4,5,6,7 };
	Datatype inord[] = { 3,2,4,1,5,7,6 };
	BiTreeNode rootnode;
	BiTree root = &rootnode;
	CreateBiTree(preord, inord, 7, &root);
 	printf("\nLevelOrder:\n");
	LevelOrder(root);*/
	printf("\nthe number of leafnode is %d", BitreeLeaf(p));
	printf("\nthe number of depth is %d", BitreeDepth(p));
	printf("\nthe tree is complete binary tree ?: %d", LevelOrder3(p));
}