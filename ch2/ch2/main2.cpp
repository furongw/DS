#include <stdio.h>
#include "uniquearray.h"

int main()
{
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
	printf("\n%d", item);
}