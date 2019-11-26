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







#endif // !UNIQUEARRAY