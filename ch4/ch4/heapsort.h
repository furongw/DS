#ifndef HEAPSORT
#define HEAPSORT
/*堆排序的实现*/
#include "tree.h"

typedef struct Node
{
	Datatype key;
}node;

//小顶堆
void Sift(node *r, int k, int m)
{
	/*假设r[k+1...m]满足小顶堆的性质，
	本算法调整r[k]使得整个序列r[k,...m]满足小顶堆的性质*/
	int i,j,x,t;
	bool finished;
	i = k;
	j = 2 * i;
	x = r[k].key;
	finished = false;
	t = r[k].key;  //暂存根的数据
	while (j <= m & !finished)
	{
		if (j<m && r[j].key >r[j + 1].key)  //若存在右子树且右子树树根的关键字小，沿右分支筛选
		{
			j = j + 1;
		}
		if (x <= r[j].key)
		{
			finished = true;  //若根上的数比两子树根上的最小数还小，筛选完毕
		}
		else  //否则，沿该子树筛选
		{
			r[i] = r[j];
			i = j;
			j = 2 * i;
		}
	}
	r[i].key = t;
}

//对r[1...n]进行堆排序，算法完成后，r[1...n]中记录按关键字自小至大排列
void Heapsort(node *r,int n)
{
	int i,tmp;
	for (i = n/2; i >= 1; i--)
	{
		Sift(r, i, n);
	}
	for (i = n; i >= 2; i--)
	{
		//堆顶元素和堆中最后一个元素交换
		tmp = r[1].key;
		r[1] = r[i];
		r[i].key = tmp;
		Sift(r, 1, i - 1);  //调整r[1]使得r[1,...,i-1]变成堆
	}
}



#endif // !HEAPSORT
