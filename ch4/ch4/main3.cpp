# include <stdio.h>
#include"heapsort.h"

#include <iostream>
#define TREESIZE 5




int main()
{
	node bt[TREESIZE+1];
	int i;
	//为了方便堆排序的测试，建立一棵顺序结构存储的二叉树
	//若一结点序号为i（从1开始），则它的左右孩子分别为2i和2i+1
	for (i = 1; i <= TREESIZE; i++)
	{
		std::cin >> bt[i].key;
	}
	printf("before sort:\n");
	for (i = 1; i <= TREESIZE; i++)
	{
		printf("%d ", bt[i].key);
	}
	Heapsort(bt, TREESIZE);
	printf("\nafter sort:\n");
	for (i = 1; i <= TREESIZE; i++)
	{
		printf("%d ", bt[i].key);
	}
}