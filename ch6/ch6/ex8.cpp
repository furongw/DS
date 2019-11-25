#include <stdio.h>
#include<math.h>
#define n 10



int rent(int i, int j)
{
	int value;
	value = j - i;
	return pow(value, 3)+190;
}

int trip(int i, int j)
{
	if (i == j)return 0;
	int cost[n];//��վ1��վn+1����С����
	int plan[n] = {0};//��վ1��վn+1�����»��ѷ�����ĸ���
	int k;
	for (k = 0; k < n; k++)
	{
		cost[k] = rent(0, k);  //��ʼ��
	}
	int m;
	for (k = 0; k < n; k++)
	{
		for (m = 0; m < k; m++)
		{
			cost[k] = (cost[k] < cost[m] + rent(m, k)) ? cost[k] : cost[m] + rent(m, k);
			plan[k] = (cost[k] < cost[m] + rent(m, k)) ? plan[k] : m;
		}
	}
	//����������·��
	for (k = n - 1; k > 0; k = plan[k])
	{
		printf("%d", k+1);
		printf("<--");
	}
	printf("1");
}

int main()
{
	trip(0, n - 1);
}