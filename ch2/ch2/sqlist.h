#ifndef SQLIST
#define SQLIST
# include "../../ch1/ch1/all.h"
# include <stdlib.h>
/*线性表算法*/

# define MAXSIZE 10

typedef struct Sqlist
{
	Datatype* elem;  //存储空间基址
	int lenth;  //当前长度
	int listsize;  //当前分配的存储容量
}SqList,*ListPtr;

//初始化
Status List_Init(ListPtr L)
{
	Status status = fatal;
	L->elem = (Datatype*)malloc((MAXSIZE + 1) * sizeof(Datatype));  //分配存储空间，申请MAXSIZE+1个数据元素单元
	if (L->elem)  //检查是否成功
	{
		L->lenth = 0;
		status = success;
	}
	return status;
}

//按位置查找
Status List_Retrive(ListPtr L, int pos, Datatype* elem)
{
	//pos查找位置，elem存放查找数据
	Status status = range_error;
	int len = L->lenth;
	if (1 <= pos && pos <= len)  //检查参数是否合法
	{
		*elem = L->elem[pos];
		status = success;
	}
	return status;
}

//按元素值查找
Status List_Locate(ListPtr L, Datatype elem, int* pos)
{
	Status status = range_error;
	int len = L->lenth;
	int i = 1;
	while (i <= len && L->elem[i] != elem)  //元素依次比较
	{
		i++;
	}
	if (i <= len)  //找到
	{
		*pos = i;
		status = success;
	}
	return status;
}


//在pos处插入元素
Status List_Insert(ListPtr L, int pos, Datatype elem)
{
	Status status = range_error;
	int len = L->lenth;
	int i;
	if (len == MAXSIZE)
	{
		status = overflow;
	}
	else if (1 <= pos && pos <= len + 1)
	{
		for (i = len; i >= pos; i--)
		{
			L->elem[i + 1] = L->elem[i];  //数据元素后移一个位置
		}
		L->elem[pos] = elem;
		L->lenth++;
		status = success;
	}
	return status;
}

//顺序表删除操作
Status List_Remove(ListPtr L, int pos)
{
	Status status = range_error;
	int len = L->lenth;
	int i;
	if (1 <= pos && pos <= len)  //检查删除位置是否合法
	{
		//检查通过，数据元素依次向前移动一个位置
		for (i = pos; i < len; i++)
		{
			L->elem[i] = L->elem[i + 1];  
			L->lenth--;  //表长减1
			status = success;
		}
		return success;
	}
}
#endif // !SQLIST
