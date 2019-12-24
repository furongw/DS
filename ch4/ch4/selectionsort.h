#ifndef SELECTIONSORT
#define SELECTIONSORT

typedef struct DataType
{
	int key;
}DataType;

void Simple_Select_Sort(DataType R[], int n)
{
	//对R[1...n]作升序排列
	int i,j,k;
	for (i = 1; i < n; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)
		{
			if (R[j].key < R[k].key)
			{
				k = j;  //找本趟关键字最小的记录
			}
		}
		if (i != k)  //最小记录不为i，则交换
		{
			R[0] = R[k];
			R[k] = R[i];
			R[i] = R[0];
		}
	}
}
#endif // !SELECTIONSORT
