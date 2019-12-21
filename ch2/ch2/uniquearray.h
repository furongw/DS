#ifndef UNIQUEARRAY
#define UNIQUEARRAY
#define MAXQUEUE 10 //�����
#define MAXSTACK 100 //���ջ
#include "../../ch1/ch1/all.h"
#include<stdlib.h>


/*ջ*/
//ջ��˳��洢
typedef struct stack
{
	int top;  //ջ��Ԫ�ص�λ��
	Datatype entry[MAXSTACK];  //���ջ��Ԫ�ص�λ��
}Stack,*StackPtr;

//˳��ջ��ջ������ʵ��
Status Stack_Push(StackPtr s, Datatype item)
{
	Status outcome = success;
	if (s->top == MAXSTACK - 1)
	{
		outcome = overflow;  //ջ��������
	}
	else
	{
		s->top++;
		s->entry[s->top] = item;  //����Ԫ�ط���topλ��
	}
	return outcome;
}

//˳��ջ��ջ
Status Stack_Pop(StackPtr s, Datatype* item)
{
	Status outcome = success;
	if (s->top == -1)
	{
		outcome = underflow;  //ջ��������
	}
	else
	{
		*item = s->entry[s->top--];  //top��ָ����Ԫ�ط���item��top�ټ�1
	}
	return outcome;
}

//ջ����ʽ�洢
//������Ͷ���
typedef struct node
{
	Datatype entry;
	struct node* next;
}StackNode, *StackNodePtr;

//��ջ���Ͷ���
typedef struct stack
{
	StackNodePtr top;  //ָ��ջ����ָ��
}Stack2,*StackPtr2;

//��ջ��ջ����
Status Stack_Push(StackPtr2 s, Datatype item)
{
	Status outcome = success;
	StackNodePtr np = (StackNodePtr)malloc(sizeof(StackNode));
	if (!np)
	{
		outcome = overflow;  //�޷�����洢�ռ䣬�൱��ջ������
	}
	else
	{
		np->entry = item;  //װ������
		np->next = s->top;  //�����뵽�Ľ������ڱ�ͷ
		s->top = np;
	}
	return outcome;
}

//��ջ��ջ����
Status Stack_Pop(StackPtr2 s, Datatype* item)
{
	Status outcome = success;
	StackNodePtr np;
	if (!s->top)
	{
		outcome = underflow;  //ջ��������
	}
	else
	{
		np = s->top;  //ɾ��ջ��Ԫ��
		s->top = np->next;
		*item = np->entry;
		free(np);
	}
	return outcome;
}

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