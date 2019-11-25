#include <stdio.h>

#define COINTYPE 5  //Ӳ��������
#define NUMAX 10000  //infinity
#define MONEY  100//������Ǯ�������ֵ

int min(int a, int b)
{
	return a < b ? a : b;
}

void charge(int T[COINTYPE + 1],int C[MONEY],int n)
{
	//T[1]...T[n]�洢Ӳ�ҵ���ֵ,nΪ����ǰn��Ӳ��
	//������ĿҪ�󳤶�ΪL��������������C[j]�洢���Ǹ�j+1Ԫ��Ǯ���������Ӳ����
	int i,j;
	for (i = 0; i < MONEY; i++)
	{
		C[i] = NUMAX;  //��ʼ��������ֵΪ������
	}
	for (j = 0; j < MONEY; j++)
	{
		for (i = 1; i <= n; i++)
		{
			if (T[i] < j)  //���Ǯ����
			{
				C[j] = min(C[j - T[i]] + 1,C[j]);
			}
			else if (T[i] == j)  //���������Ǯ
			{
				C[j] = 1;
			}
		}
	}
}

int main()
{
	int T[COINTYPE + 1] = { 0,2,3,5,10,7 };
	int C[MONEY];
	int n = 5;
	charge(T, C, n);
	for (int i = 0; i < MONEY; i++)
	{
		printf("using the former %d types of money, we need %d coin to charge money %d\n", 3, C[i], i);
	}
}