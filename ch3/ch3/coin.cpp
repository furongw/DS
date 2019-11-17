#include <iostream>

#define ARRAY_SIZE 3



int findcoin(int total, int coin[],int min, int coincount[])
{
	/*实现给总数为total找零钱，coin[]为零钱集合，min为最小零钱面额，coincount为对应零钱面额所需零钱数*/
	int i;
	if (total < min)  //如果total小于最小面额，无解
	{
		return 0;
	}
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		if (total == coin[i])  //如果total等于某种零钱面额，成功，对应count++
		{
			coincount[i]++;
			//std::cout << "coin " << coin[i];
			return 1;
		}
		if (findcoin(total - coin[i], coin, min,coincount))  //递归寻找减去改种面额的零钱后的总额的零钱
		{
			coincount[i]++;
			//std::cout << "coin " << coin[i];
			return 1;
		}
	}
	return 0;
	//该算法有点像是暴力穷举了，时间复杂度很高，只寻找到一种结果就返回
}


int main()
{
	int coin[ARRAY_SIZE] = {7,3,2};  //硬币集合
	int coincount[ARRAY_SIZE] = { 0 };  //对应硬币数目
	int i;
	int min = coin[0];  //求最小硬币
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		if (coin[i] < min)
		{
			min = coin[i];
		}
	}
	if (findcoin(24, coin, min, coincount)==1)
	{
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			std::cout << "the number of coin " << coin[i] << " is " << coincount[i] << std::endl;  //输出
		}
	}
	else
	{
		std::cout << "no way" << std::endl;
	}
}