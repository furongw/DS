#include <stdio.h>
#include "binsortree.h"
#include "tree.h"

#define NUMSIZE 10

//生成一个二叉搜索树
void initbst(BiTree &p, Datatype data[],int n)
{
	p = NULL;
	int i;
	for (i = 0; i < n; i++)
	{
		Insert( data[i],p);
	}
}


int main()
{
	Datatype num[NUMSIZE] = { 1,3,2,4,8,7,0.20,28,9};
	BiTree BST,p,q ;
	
	//建立二叉搜索树
	initbst(BST, num,NUMSIZE);
	printf("preorder:\n");
	PreOrder(BST);
	printf("\ninorder:\n");
	InOrder(BST);
	printf("\npostorder:\n");
	PostOrder(BST);

	//测试二叉搜索树寻找算法
	//if (Find(-2, BST))
	/*if(IterFind(7,BST))
	{
		printf("\nsuccess!\n");
	}
	else
	{
		printf("\n404\n");
	}
	printf("the max is: %d", Findmax(BST)->data);*/
	if (SearchBST(BST, 9, &p, &q))
	{
		printf("\nsuccess!\n");
	}
	else
	{
		printf("\n404\n");
	}
	
	DeleteBiTreeNode(&BST, 28);
	printf("\ninorder:\n");
	InOrder(BST);
	
}