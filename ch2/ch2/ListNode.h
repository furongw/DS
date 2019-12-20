#ifndef LISTNODE
# define LISTNODE
#include "../../ch1/ch1/all.h"
/*链表*/

//类型定义
typedef struct node
{
	Datatype data; //数据域
	struct node* next; //指针域
}ListNode,*ListNodePtr;

//按位置查找链表元素
Status List_Retrive(ListNodePtr L, int pos, Datatype* elem)
{
	Status status = range_error;
	ListNodePtr p = (*L).next;  //带头结点，移动p指向第一个元素结点
	int i = 1;
	while (p && i < pos)  //p指向的结点存在且未到达指定位置
	{
		i++;  //计数器加1
		p = p->next;  //移动指针p后移
	}
	if (p && i == pos)  //找到指定位置，且该节点存在
	{
		*elem = p->data;
		status = success;
	}
	return status;
}

//按值查找
Status List_Locate(ListNodePtr L, DataType elem, int* pos)
{
	Status status = range_error;
	ListNodePtr p = (*L).next;
	int i = 1;
	while (p && p->data!=elem)
	{
		i++;
		p = p->next;  //指针后移，同时计数器加1
	}
	if (p)
	{
		*pos = i;
		status = success;
	}
	return status;
}

//单链表上的插入操作
//按位置查找链表元素
Status List_Setposition(ListNodePtr L, int pos, ListNodePtr *pre)
{
	Status status = range_error;
	ListNodePtr p = (*L).next;  //带头结点，移动p指向第一个元素结点
	*pre = p;
	int i = 1;
	while (p && i < pos)  //p指向的结点存在且未到达指定位置
	{
		i++;  //计数器加1
		*pre = p;  //前驱
		p = p->next;  //移动指针p后移
	}
	if (p && i == pos)  //找到指定位置，且该节点存在
	{
		status = success;
	}
	return status;
}

Status List_Insert(ListNodePtr L, int pos, DataType elem)
{
	Status status;
	ListNodePtr s;
	ListNodePtr pre;
	status = List_Setposition(L, pos-1, &pre);  //找插入位置的前驱
	if (status == success)
	{
		s = (ListNodePtr)malloc(sizeof(ListNode));
		if (s)
		{
			s->data = elem;
			s->next = pre->next;
			pre->next = s;
		}
		else
		{
			status = fatal;
		}

	}
	return status;
}

Status List_Remove(ListNodePtr L, int pos)
{
	Status status;
	ListNodePtr ptr, q;
	status = List_Setposition(L, pos - 1, &ptr);  //找删除位置的前驱
	if (status == success)
	{
		q = ptr->next;  //修改指针
		ptr->next = q->next;
		free(q);  //释放存储空间
	}
	return status;
}

//单链表的创建算法
Status List_Create(ListNodePtr* L, DataType elem[], int n)
{
	Status status = success;
	ListNodePtr p, q;
	int i = n - 1;  //指向最后一个数据元素
	q = (ListNodePtr)malloc(sizeof(ListNode));  //建立带头结点的空表
	//q->next = NULL;
	while (i >= 0)  //还存在数据元素未处理
	{
		p = (ListNodePtr)malloc(sizeof(ListNode));
		if (!p)  //空间分配失败，退出
		{
			status = fatal;
			break;
		}
		p->data = elem[i];  //新结点
		p->next = q->next;  //插入在表头
		q->next = p;
		i = i - 1;
	}
	*L = q;
	return status;
}


#endif // !LISTNODE
