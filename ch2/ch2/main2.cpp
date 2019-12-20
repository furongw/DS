#include <stdio.h>
#include "uniquearray.h"
#include "sqlist.h"

int main()
{
	//数组
	SqList sq;
	ListPtr p = &sq;
	//测试数组初始化
	List_Init(&sq);
	int i;
	//测试插入
	for (i = 0; i < 9; i++)
	{
		List_Insert(&sq, 1, i);  
	}
	for (i = 0; i < 9; i++)
	{
		printf("%d ", p->elem[i+1]);
	}
	printf("\n");
	//测试删除
	List_Remove(&sq, 1);
	for (i = 0; i < 8; i++)
	{
		printf("%d ", p->elem[i + 1]);
	}

	//队列
	/*
	QueuePtr q;
	//队列初始化测试
	Queue_Init(&q);
	printf("%d\n", Queue_Init(&q) == success);

	int i;
	for (i = 0; i < 5; i++)
	{
		Queue_EnQueue(q, i);  //入队测试
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", q->entry[i]);
	}

	//循环队列出队测试
	int item;
	Queue_DeQueue(q, &item);
	printf("\n%d", item);*/
}