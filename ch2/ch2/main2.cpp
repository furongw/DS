#include <stdio.h>
#include "uniquearray.h"
#include "sqlist.h"
#include "ListNode.h"

int main()
{
	/*
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
	*/

	//����
	//�ȴ���һ���򵥵�����
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
	//���԰�λ�ò���
	List_Retrive(&p, 2, &find);
	printf("%d\n", find);
	//���԰�ֵ����
	List_Locate(&p, 3, &pos);
	printf("%d\n", pos);
	//���Բ������
	printf("after insert:\n");
	List_Insert(&p, 2, 5);
	for (pos = 1; pos <= 5; pos++)
	{
		List_Retrive(&p, pos, &find);
		printf("%d ", find);
	}
	printf("\n");
	//����ɾ������
	printf("after remove:\n");
	List_Remove(&p, 2);
	for (pos = 1; pos <= 4; pos++)
	{
		List_Retrive(&p, pos, &find);
		printf("%d ", find);
	}
	printf("\n");
	//���Ե�����Ĵ���
	printf("after init:\n");
	int elem[7] = { 1,2,3,4,3,2,1 };
	List_Create(&ptr, elem,7);
	//ʵ���������Ѿ��޸���Ptrָ���ָ��
	for (pos = 1; pos <= 7; pos++)
	{
		List_Retrive(*&ptr, pos, &find);
		printf("%d ", find);
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