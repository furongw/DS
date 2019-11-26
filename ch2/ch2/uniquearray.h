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







#endif // !UNIQUEARRAY