#ifndef UNIQUEARRAY
#define UNIQUEARRAY
#define MAXQUEUE 10 //最长队列
#include "../../ch1/ch1/all.h"
#include<stdlib.h>


/*队列的存储*/
typedef int DataType;  //数据元素类型

typedef struct queue
{
	int front, rear;  //队头和队尾指针
	DataType entry[MAXQUEUE];  //数据元素存储空间
}Queue,*QueuePtr;

//循环队列初始化
Status Queue_Init(QueuePtr* q)
{
	Status outcome = fatal;
	QueuePtr queueptr = (QueuePtr)malloc(sizeof(queue));
	if (queueptr)  //如果申请成功
	{
		queueptr->front = queueptr->rear = -1;
		*q = queueptr;
		outcome = success;
	}
	return outcome;
}

//循环队列的判空
bool Queue_Empty(QueuePtr q)
{
	return q->front == q->rear;  //两个指针相等
}

//循环队列的判满
bool Queue_Full(QueuePtr q)
{
	return ((q->rear + 1) % MAXQUEUE == q->front);
}

//入队
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

//循环队列的出队
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