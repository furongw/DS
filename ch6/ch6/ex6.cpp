#include <stdio.h>

#define COINTYPE 5  //硬币种类数
#define NUMAX 10000  //infinity
#define MONEY  100//所需找钱数的最大值

int min(int a, int b)
{
	return a < b ? a : b;
}

void charge(int T[COINTYPE + 1],int C[MONEY],int n)
{
	//T[1]...T[n]存储硬币的面值,n为运用前n种硬币
	//由于题目要求长度为L的数组所以这里C[j]存储的是给j+1元找钱所需的最少硬币数
	int i,j;
	for (i = 0; i < MONEY; i++)
	{
		C[i] = NUMAX;  //初始化，均赋值为正无穷
	}
	for (j = 0; j < MONEY; j++)
	{
		for (i = 1; i <= n; i++)
		{
			if (T[i] < j)  //如果钱够找
			{
				C[j] = min(C[j - T[i]] + 1,C[j]);
			}
			else if (T[i] == j)  //如果面额等于钱
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