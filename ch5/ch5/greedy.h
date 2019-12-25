#ifndef GREEDY
# define GREEDY

//分数背包问题最优解的贪心算法
float greedy_knapsack(float p[], float w[], float m, float x[], float n)
{
	//p[n]和w[n]是按性价比降序排列的n件物品的价值和重量，m是背包的容量大小，而x[n]
	int i;
	float cu = m;
	float sum = 0;  //cu是背包剩余容量
	for (i = 0; i < n; i++)
	{
		x[i] = 0;  //将解向量初始化为零
	}
	for (i = 0; i < n; i++)  //整装
	{
		if (w[i] > cu)
		{
			break;
		}
		x[i] = 1;
		cu -= w[i];
		sum += p[i];
	}
	if (i < n && cu>0)  //散装
	{
		x[i] = cu / w[i];
		sum += p[i] * cu / w[i];
	}
	return sum;
}

#endif // !GREEDY
