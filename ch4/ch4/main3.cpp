# include <stdio.h>
#include"heapsort.h"

#include <iostream>
#define TREESIZE 5




int main()
{
	node bt[TREESIZE+1];
	int i;
	//Ϊ�˷��������Ĳ��ԣ�����һ��˳��ṹ�洢�Ķ�����
	//��һ������Ϊi����1��ʼ�������������Һ��ӷֱ�Ϊ2i��2i+1
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