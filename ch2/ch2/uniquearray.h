#ifndef UNIQUEARRAY
#define UNIQUEARRAY
#define MAXQUEUE 10 //最长队列
#define MAXSTACK 100 //最大栈
#include "../../ch1/ch1/all.h"
#include<stdlib.h>


/*栈*/
//栈的顺序存储
typedef struct stack
{
	int top;  //栈顶元素的位置
	Datatype entry[MAXSTACK];  //存放栈顶元素的位置
}Stack,*StackPtr;

//顺序栈入栈操作的实现
Status Stack_Push(StackPtr s, Datatype item)
{
	Status outcome = success;
	if (s->top == MAXSTACK - 1)
	{
		outcome = overflow;  //栈满则上溢
	}
	else
	{
		s->top++;
		s->entry[s->top] = item;  //数据元素放入top位置
	}
	return outcome;
}

//顺序栈出栈
Status Stack_Pop(StackPtr s, Datatype* item)
{
	Status outcome = success;
	if (s->top == -1)
	{
		outcome = underflow;  //栈空则下溢
	}
	else
	{
		*item = s->entry[s->top--];  //top所指数据元素放入item，top再减1
	}
	return outcome;
}

//栈的链式存储
//结点类型定义
typedef struct node
{
	Datatype entry;
	struct node* next;
}StackNode, *StackNodePtr;

//链栈类型定义
typedef struct stack
{
	StackNodePtr top;  //指向栈顶的指针
}Stack2,*StackPtr2;

//链栈入栈操作
Status Stack_Push(StackPtr2 s, Datatype item)
{
	Status outcome = success;
	StackNodePtr np = (StackNodePtr)malloc(sizeof(StackNode));
	if (!np)
	{
		outcome = overflow;  //无法分配存储空间，相当于栈满上溢
	}
	else
	{
		np->entry = item;  //装填结点域
		np->next = s->top;  //所申请到的结点插入在表头
		s->top = np;
	}
	return outcome;
}

//链栈出栈操作
Status Stack_Pop(StackPtr2 s, Datatype* item)
{
	Status outcome = success;
	StackNodePtr np;
	if (!s->top)
	{
		outcome = underflow;  //栈空则下溢
	}
	else
	{
		np = s->top;  //删除栈顶元素
		s->top = np->next;
		*item = np->entry;
		free(np);
	}
	return outcome;
}

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