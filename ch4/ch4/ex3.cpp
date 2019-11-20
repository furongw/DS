#include <stdio.h>
#include <iostream>
#include "tree.h"
#include "heapsort.h"
#define TREESIZE 5

//练习三已知部分序列为大顶堆，加入一数后重新调整为大顶堆
//大顶堆
void Siftbig(node* r, int k, int m)
{
	/*假设r[1...k-1满足大顶堆的性质，
	本算法调整r[k]使得整个序列r[1...k]满足大顶堆的性质*/
	int i, j, x, t,tmp;
	bool finished;

	i = k;
	j = i/2;
	x = r[k].key;
	finished = false;
	t = r[k].key;  //暂存根的数据
	while (j >=m  && !finished) //沿双亲上升
	{
		if (x < r[j].key)
		{
			finished = true;  //若根上的数比新加数大，筛选完毕
		}
		else  //否则，沿双亲筛选
		{
			tmp = r[i].key;
			r[i] = r[j];
			r[j].key = tmp;
			i = j;
			j = i / 2;
		}
	}
}

//改变调整大顶堆顺序之后的heapsort算法未完成，错误出在挑出最大数后的算法逻辑，以后再改goodnight
//对r[1...n]进行堆排序，算法完成后，r[1...n]中记录按关键字自大至小排列
void Heapsortbig(node* r, int n)
{
	int i, tmp;
	for (i = 1; i <= n; i++)
	{
		Siftbig(r, i,1);
	}
	for (i = 1; i <= n; i++)
	{
		//堆顶元素和堆中最后一个元素交换
		tmp = r[n-i+1].key;
		r[n - i + 1] = r[1]  ;
		r[1].key = tmp;
		Siftbig(r, i-1,1);  //调整r[1]使得r[1,...,i-1]变成堆
	}
}

int main()
{
	node bt[TREESIZE + 1];
	int i;
	//为了方便堆排序的测试，建立一棵顺序结构存储的二叉树
	//若一结点序号为i（从1开始），则它的左右孩子分别为2i和2i+1
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