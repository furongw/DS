#include <stdio.h>
#include "uniquearray.h"

int main()
{
	QueuePtr q;
	//���г�ʼ������
	Queue_Init(&q);
	printf("%d\n", Queue_Init(&q) == success);

	int i;
	for (i = 0; i < 5; i++)
	{
		Queue_EnQueue(q, i);  //��Ӳ���
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", q->entry[i]);
	}

	//ѭ�����г��Ӳ���
	int item;
	Queue_DeQueue(q, &item);
	printf("\n%d", item);
}