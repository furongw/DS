#ifndef LISTNODE
# define LISTNODE
#include "../../ch1/ch1/all.h"
/*����*/

//���Ͷ���
typedef struct node
{
	Datatype data; //������
	struct node* next; //ָ����
}ListNode,*ListNodePtr;

//��λ�ò�������Ԫ��
Status List_Retrive(ListNodePtr L, int pos, Datatype* elem)
{
	Status status = range_error;
	ListNodePtr p = (*L).next;  //��ͷ��㣬�ƶ�pָ���һ��Ԫ�ؽ��
	int i = 1;
	while (p && i < pos)  //pָ��Ľ�������δ����ָ��λ��
	{
		i++;  //��������1
		p = p->next;  //�ƶ�ָ��p����
	}
	if (p && i == pos)  //�ҵ�ָ��λ�ã��Ҹýڵ����
	{
		*elem = p->data;
		status = success;
	}
	return status;
}

//��ֵ����
Status List_Locate(ListNodePtr L, DataType elem, int* pos)
{
	Status status = range_error;
	ListNodePtr p = (*L).next;
	int i = 1;
	while (p && p->data!=elem)
	{
		i++;
		p = p->next;  //ָ����ƣ�ͬʱ��������1
	}
	if (p)
	{
		*pos = i;
		status = success;
	}
	return status;
}

//�������ϵĲ������
//��λ�ò�������Ԫ��
Status List_Setposition(ListNodePtr L, int pos, ListNodePtr *pre)
{
	Status status = range_error;
	ListNodePtr p = (*L).next;  //��ͷ��㣬�ƶ�pָ���һ��Ԫ�ؽ��
	*pre = p;
	int i = 1;
	while (p && i < pos)  //pָ��Ľ�������δ����ָ��λ��
	{
		i++;  //��������1
		*pre = p;  //ǰ��
		p = p->next;  //�ƶ�ָ��p����
	}
	if (p && i == pos)  //�ҵ�ָ��λ�ã��Ҹýڵ����
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
	status = List_Setposition(L, pos-1, &pre);  //�Ҳ���λ�õ�ǰ��
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
	status = List_Setposition(L, pos - 1, &ptr);  //��ɾ��λ�õ�ǰ��
	if (status == success)
	{
		q = ptr->next;  //�޸�ָ��
		ptr->next = q->next;
		free(q);  //�ͷŴ洢�ռ�
	}
	return status;
}

//������Ĵ����㷨
Status List_Create(ListNodePtr* L, DataType elem[], int n)
{
	Status status = success;
	ListNodePtr p, q;
	int i = n - 1;  //ָ�����һ������Ԫ��
	q = (ListNodePtr)malloc(sizeof(ListNode));  //������ͷ���Ŀձ�
	//q->next = NULL;
	while (i >= 0)  //����������Ԫ��δ����
	{
		p = (ListNodePtr)malloc(sizeof(ListNode));
		if (!p)  //�ռ����ʧ�ܣ��˳�
		{
			status = fatal;
			break;
		}
		p->data = elem[i];  //�½��
		p->next = q->next;  //�����ڱ�ͷ
		q->next = p;
		i = i - 1;
	}
	*L = q;
	return status;
}


#endif // !LISTNODE
