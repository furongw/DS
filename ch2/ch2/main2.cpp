#include <stdio.h>
#include "uniquearray.h"
#include "sqlist.h"
#include "ListNode.h"

int main()
{
	/*
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
	*/

	//链表
	//先创建一个简单的链表
	ListNode a, b, c, d;
	ListNode p;
	p.next = &a;
	ListNodePtr ptr = &p;
	int find,pos;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	a.data = 1;
	b.data = 2;
	c.data = 3;
	d.data = 4;
	//测试按位置查找
	List_Retrive(&p, 2, &find);
	printf("%d\n", find);
	//测试按值查找
	List_Locate(&p, 3, &pos);
	printf("%d\n", pos);
	//测试插入操作
	printf("after insert:\n");
	List_Insert(&p, 2, 5);
	for (pos = 1; pos <= 5; pos++)
	{
		List_Retrive(&p, pos, &find);
		printf("%d ", find);
	}
	printf("\n");
	//测试删除操作
	printf("after remove:\n");
	List_Remove(&p, 2);
	for (pos = 1; pos <= 4; pos++)
	{
		List_Retrive(&p, pos, &find);
		printf("%d ", find);
	}
	printf("\n");
	//测试单链表的创建
	printf("after init:\n");
	int elem[7] = { 1,2,3,4,3,2,1 };
	List_Create(&ptr, elem,7);
	//实际上这里已经修改了Ptr指针的指向。
	for (pos = 1; pos <= 7; pos++)
	{
		List_Retrive(*&ptr, pos, &find);
		printf("%d ", find);
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