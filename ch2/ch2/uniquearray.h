#ifndef UNIQUEARRAY
#define UNIQUEARRAY
#define MAXQUEUE 10 //�����
#include "../../ch1/ch1/all.h"
#include<stdlib.h>


/*���еĴ洢*/
typedef int DataType;  //����Ԫ������

typedef struct queue
{
	int front, rear;  //��ͷ�Ͷ�βָ��
	DataType entry[MAXQUEUE];  //����Ԫ�ش洢�ռ�
}Queue,*QueuePtr;

//ѭ�����г�ʼ��
Status Queue_Init(QueuePtr* q)
{
	Status outcome = fatal;
	QueuePtr queueptr = (QueuePtr)malloc(sizeof(queue));
	if (queueptr)  //�������ɹ�
	{
		queueptr->front = queueptr->rear = -1;
		*q = queueptr;
		outcome = success;
	}
	return outcome;
}

//ѭ�����е��п�
bool Queue_Empty(QueuePtr q)
{
	return q->front == q->rear;  //����ָ�����
}

//ѭ�����е�����
bool Queue_Full(QueuePtr q)
{
	return ((q->rear + 1) % MAXQUEUE == q->front);
}

//���
Status Queue_EnQueue(QueuePtr q, DataType item)
{
	Status outcome = overflow;
	if (!Queue_Full(q))
	{
		q->rear = (q->rear + 1) % MAXQUEUE;
		q->entry[q->rear] = item;
		outcome = success;
	}
	return outcome;
}

//ѭ�����еĳ���
Status Queue_DeQueue(QueuePtr q, DataType* item)
{
	Status outcome = underflow;
	if (!Queue_Empty(q))
	{
		q->front = (q->front + 1) % MAXQUEUE;
		*item = q->entry[q->front];
		outcome = success;
	}
	return outcome;
}






#endif // !UNIQUEARRAY