#include <stdio.h>
#include "uniquearray.h"
#include "sqlist.h"

int main()
{
	//����
	SqList sq;
	ListPtr p = &sq;
	//���������ʼ��
	List_Init(&sq);
	int i;
	//���Բ���
	for (i = 0; i < 9; i++)
	{
		List_Insert(&sq, 1, i);  
	}
	for (i = 0; i < 9; i++)
	{
		printf("%d ", p->elem[i+1]);
	}
	printf("\n");
	//����ɾ��
	List_Remove(&sq, 1);
	for (i = 0; i < 8; i++)
	{
		printf("%d ", p->elem[i + 1]);
	}

	//����
	/*
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
	printf("\n%d", item);*/
}