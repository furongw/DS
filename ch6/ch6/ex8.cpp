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
	int cost[n];//从站1到站n+1的最小花费
	int plan[n] = {0};//从站1到站n+1的最下花费方案的母结点
	int k;
	for (k = 0; k < n; k++)
	{
		cost[k] = rent(0, k);  //初始化
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
	//倒序输出最佳路径
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