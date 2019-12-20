#ifndef SQLIST
#define SQLIST
# include "../../ch1/ch1/all.h"
# include <stdlib.h>
/*���Ա��㷨*/

# define MAXSIZE 10

typedef struct Sqlist
{
	Datatype* elem;  //�洢�ռ��ַ
	int lenth;  //��ǰ����
	int listsize;  //��ǰ����Ĵ洢����
}SqList,*ListPtr;

//��ʼ��
Status List_Init(ListPtr L)
{
	Status status = fatal;
	L->elem = (Datatype*)malloc((MAXSIZE + 1) * sizeof(Datatype));  //����洢�ռ䣬����MAXSIZE+1������Ԫ�ص�Ԫ
	if (L->elem)  //����Ƿ�ɹ�
	{
		L->lenth = 0;
		status = success;
	}
	return status;
}

//��λ�ò���
Status List_Retrive(ListPtr L, int pos, Datatype* elem)
{
	//pos����λ�ã�elem��Ų�������
	Status status = range_error;
	int len = L->lenth;
	if (1 <= pos && pos <= len)  //�������Ƿ�Ϸ�
	{
		*elem = L->elem[pos];
		status = success;
	}
	return status;
}

//��Ԫ��ֵ����
Status List_Locate(ListPtr L, Datatype elem, int* pos)
{
	Status status = range_error;
	int len = L->lenth;
	int i = 1;
	while (i <= len && L->elem[i] != elem)  //Ԫ�����αȽ�
	{
		i++;
	}
	if (i <= len)  //�ҵ�
	{
		*pos = i;
		status = success;
	}
	return status;
}


//��pos������Ԫ��
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
			L->elem[i + 1] = L->elem[i];  //����Ԫ�غ���һ��λ��
		}
		L->elem[pos] = elem;
		L->lenth++;
		status = success;
	}
	return status;
}

//˳���ɾ������
Status List_Remove(ListPtr L, int pos)
{
	Status status = range_error;
	int len = L->lenth;
	int i;
	if (1 <= pos && pos <= len)  //���ɾ��λ���Ƿ�Ϸ�
	{
		//���ͨ��������Ԫ��������ǰ�ƶ�һ��λ��
		for (i = pos; i < len; i++)
		{
			L->elem[i] = L->elem[i + 1];  
			L->lenth--;  //����1
			status = success;
		}
		return success;
	}
}
#endif // !SQLIST
