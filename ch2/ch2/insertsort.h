#ifndef INSERTSORT
#define INSERTSORT

typedef struct DataType
{
	int key;
}DataType;

void Direct_Insert_Sort(DataType R[], int n)
{
	//按关键字升序排列，从第2个记录开始，R[0]作为监视哨
	int i,j;
	for (i = 2; i <= n; ++i)
	{
		if (R[i].key < R[i - 1].key)
		{
			R[0].key = R[i].key;
			for (j = i - 1; R[0].key < R[j].key; j--)//有序部分最后一个开始向前探索，同时后移
			{
				R[j + 1] = R[j];
			}
			R[j + 1] = R[0];  //将记录插入到正确位置
		}
	}
}

//折半插入排序
void BInsertSort(int a[], int size)
{
	int i, j,mid;
	int temp = 0;
	int low = 0;
	int high = 0;
	for (i = 1; i < size;i++)
	{
		low = 0;  //初始化low，最开始为0
		high = i - 1;  //初始化high,最开始为i-1，为有序区最大索引
		temp = a[i];  //采用折半查找法判断插入位置，最终变量low表示插入位置
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] > temp)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (j = i; j > low; j--)  //有序表中插入位置后的元素统一后移
		{
			a[j] = a[j - 1];
		}
		a[low] = temp;  //插入元素
	}
}

//希尔排序算法
void Shell_Insert_Sort(DataType R[], int n, int d[], int t)
{
	int i, j, k, dk;
	//待排序序列为R[1,...,n],d[0,...,t-1]为增量序列
	for (k = 0; k < t; k++)
	{
		dk = d[k];
		for (i = dk + 1; i <= n; ++i)  //将R[i]插入到所属有序子序列中
		{
			if (R[i].key < R[i - dk].key)
			{
				R[0] = R[i];  //监视哨R[0]
				for (j = i - dk; j > 0 && R[0].key < R[j].key; j = j - dk)
				{
					R[j + dk] = R[j];  //寻找插入位置，同时数据后移
				}
				R[j + dk] = R[0];  //插入到正确位置
			}
		}
	}
}
#endif // !INSERTSORT
