#ifndef HEAPSORT
#define HEAPSORT
/*�������ʵ��*/
#include "tree.h"

typedef struct Node
{
	Datatype key;
}node;

//С����
void Sift(node *r, int k, int m)
{
	/*����r[k+1...m]����С���ѵ����ʣ�
	���㷨����r[k]ʹ����������r[k,...m]����С���ѵ�����*/
	int i,j,x,t;
	bool finished;
	i = k;
	j = 2 * i;
	x = r[k].key;
	finished = false;
	t = r[k].key;  //�ݴ��������
	while (j <= m & !finished)
	{
		if (j<m && r[j].key >r[j + 1].key)  //�������������������������Ĺؼ���С�����ҷ�֧ɸѡ
		{
			j = j + 1;
		}
		if (x <= r[j].key)
		{
			finished = true;  //�����ϵ��������������ϵ���С����С��ɸѡ���
		}
		else  //�����ظ�����ɸѡ
		{
			r[i] = r[j];
			i = j;
			j = 2 * i;
		}
	}
	r[i].key = t;
}

//��r[1...n]���ж������㷨��ɺ�r[1...n]�м�¼���ؼ�����С��������
void Heapsort(node *r,int n)
{
	int i,tmp;
	for (i = n/2; i >= 1; i--)
	{
		Sift(r, i, n);
	}
	for (i = n; i >= 2; i--)
	{
		//�Ѷ�Ԫ�غͶ������һ��Ԫ�ؽ���
		tmp = r[1].key;
		r[1] = r[i];
		r[i].key = tmp;
		Sift(r, 1, i - 1);  //����r[1]ʹ��r[1,...,i-1]��ɶ�
	}
}



#endif // !HEAPSORT
