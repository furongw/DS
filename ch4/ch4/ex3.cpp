#include <stdio.h>
#include <iostream>
#include "tree.h"
#include "heapsort.h"
#define TREESIZE 5

//��ϰ����֪��������Ϊ�󶥶ѣ�����һ�������µ���Ϊ�󶥶�
//�󶥶�
void Siftbig(node* r, int k, int m)
{
	/*����r[1...k-1����󶥶ѵ����ʣ�
	���㷨����r[k]ʹ����������r[1...k]����󶥶ѵ�����*/
	int i, j, x, t,tmp;
	bool finished;

	i = k;
	j = i/2;
	x = r[k].key;
	finished = false;
	t = r[k].key;  //�ݴ��������
	while (j >=m  && !finished) //��˫������
	{
		if (x < r[j].key)
		{
			finished = true;  //�����ϵ������¼�����ɸѡ���
		}
		else  //������˫��ɸѡ
		{
			tmp = r[i].key;
			r[i] = r[j];
			r[j].key = tmp;
			i = j;
			j = i / 2;
		}
	}
}

//�ı�����󶥶�˳��֮���heapsort�㷨δ��ɣ���������������������㷨�߼����Ժ��ٸ�goodnight
//��r[1...n]���ж������㷨��ɺ�r[1...n]�м�¼���ؼ����Դ���С����
void Heapsortbig(node* r, int n)
{
	int i, tmp;
	for (i = 1; i <= n; i++)
	{
		Siftbig(r, i,1);
	}
	for (i = 1; i <= n; i++)
	{
		//�Ѷ�Ԫ�غͶ������һ��Ԫ�ؽ���
		tmp = r[n-i+1].key;
		r[n - i + 1] = r[1]  ;
		r[1].key = tmp;
		Siftbig(r, i-1,1);  //����r[1]ʹ��r[1,...,i-1]��ɶ�
	}
}

int main()
{
	node bt[TREESIZE + 1];
	int i;
	//Ϊ�˷��������Ĳ��ԣ�����һ��˳��ṹ�洢�Ķ�����
	//��һ������Ϊi����1��ʼ�������������Һ��ӷֱ�Ϊ2i��2i+1
	for (i = 1; i <= TREESIZE; i++)
	{
		std::cin >> bt[i].key;
	}
	printf("before sort:\n");
	for (i = 1; i <= TREESIZE; i++)
	{
		printf("%d ", bt[i].key);
	}
	Heapsortbig(bt, TREESIZE);
	printf("\nafter sort:\n");
	for (i = 1; i <= TREESIZE; i++)
	{
		printf("%d ", bt[i].key);
	}
}