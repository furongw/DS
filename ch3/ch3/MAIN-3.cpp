/*第三章  递归与分治 */


#include <stdio.h>
#include <iostream>
#include "../../../Project2/Project2/algo_seqlist.h"


//2阶乘
int compute2n(int n)
{
	if (n == 1)
	{
		return 2;
	}
	if (n > 1)
	{
		return 2 * compute2n(n - 1);
	}
}

//二分查找(递归实现)
int BinSearch(ListPtr L, int high, int low, ElemType key)
{
	//在有序表L中查找关键字为key的元素
	//若存在，则查找成功，返回其在有序表中的位置，否则，查找失败，返回-1
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (L->elem[mid] == key)
		{
			return mid;
		}
		else if (L->elem[mid] > key)
		{
			return BinSearch(L, low, mid - 1, key);
		}
		else if (L->elem[mid] < key)
		{
			return BinSearch(L, mid + 1, high, key);
		}
		else
			return -1;
	}

}

//二分查找(非递归实现)
int BinSearch2(ListPtr L, int high, int low, ElemType key)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (L->elem[mid] == key)
		{
			return mid;
		}
		else if (L->elem[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

/*实现查找有序表中等于k的元素的数目，如果无则返回-1*/
//寻找下边界左侧
int BinSearchlow(ListPtr L, int high, int low, ElemType key)
{
	int mid;
	if (low > high)
	{
		return low-1;
	}
	mid = (high + low) / 2;
	if (L->elem[mid] >= key)
	{
		return BinSearchlow(L, mid-1,low, key);
	}
	else
	{
		return BinSearchlow(L,high, mid+1, key);
	}
}

//寻找上边界右侧
int BinSearchhigh(ListPtr L, int high, int low, ElemType key)
{
	int mid;
	if (high < low)
	{
		return low;
	}
	mid = (high + low) / 2;
	if (L->elem[mid] > key)
	{
		return BinSearchhigh(L, mid-1,low, key);
	}
	else
	{
		return BinSearchhigh(L, high,mid+1 , key);
	}
}

int Bincountkey(ListPtr L, int high, int low, ElemType key)
{
	//返回寻找的key的数目
	return BinSearchhigh(L, high, low, key) - BinSearchlow(L, high, low, key) - 1;
}


/*冒泡排序及其改进*/
void BubbleSort(ElemType *R, int n)
{
	//对长度为n的序列R按升序进行冒泡排序
	int i, j, swap;
	for (i = 0; i < n ; i++)
	{
		swap = 0;  //交换标志
		for (j = 0; j <= n  - i; j++)
		{
			if (R[j] > R[j + 1])  //不满足升序，交换
			{
				R[n] = R[j + 1];  //牺牲最后一个存储单元作为交换位，其实不大明白教材为什么非要拿数组里面的元素做交换位，不是增加出错的风险嘛。。
				R[j + 1] = R[j];  //书上原为牺牲第一个元素，这里我改了
				R[j] = R[n];
				swap = 1;
			}
			
		}
		if (swap == 0) break;
	}

}

/*冒泡排序的改进*/

void swap(ElemType* a, ElemType* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//记录下最后一次交换
void BubbleSort2(ElemType R[], int n)
{
	int i,j,lastExchangeIndex;
	i = n;
	while (i > 0)
	{
		lastExchangeIndex = 0;
		for (j = 0; j < n - 1; j++)
		{
			if (R[j] > R[j + 1])
			{
				swap(&R[j], &R[j + 1]);
				lastExchangeIndex = j;
			}

		}
		i = lastExchangeIndex;
	}

}

/*快速排序*/
//分治：返回划分元应在的位置
int Partition(ElemType R[], int low, int high)
{
	ElemType pivot = R[low];
	while (low < high)
	{
		while (low < high && R[high] >= pivot)
		{
			high--;
		}
		R[low] = R[high];  //小于划分元素的元素交换到低端
		while (low < high && R[low] <= pivot)
		{
			low++;
		}
		R[high] = R[low];  //大于划分元素的元素交换到高端
	}
	R[low] = pivot;  //划分元置入正确位置
	return low;  //返回划分元位置
}

//递归调用快排
void QuickSort(ElemType R[], int low, int high)
{
	if (low < high)
	{
		int pivot_position = Partition(R, low, high);
		QuickSort(R, low, pivot_position - 1);
		QuickSort(R, pivot_position + 1, high);
	}
}

/*归并排序*/
void Merge(ElemType R[], ElemType R1[], int s, int mid, int t)
{
	//表R[s...t]的两部分R[s..mid]和R[mid+1..t]已按关键字有序
	//将R[s..mid]和R[mid+1..t]合并成有序表R1[s..t]
	int k,i,j;
	for (k = s; k <= t; k++)
	{
		R1[k] = R[k];
	}
	i = s; k = s;
	j = mid + 1;
	while (i <= mid && j <= t)
	{
		if (R1[i] < R1[j])
		{
			R[k++] = R1[i++];
		}
		else
		{
			R[k++] = R1[j++];
		}
	}
	while (i <= mid)
	{
		R[k++] = R1[i++];
	}
	while (j <= t)
	{
		R[k++] = R1[j++];
	}
}

void MergeSort(ElemType R[], int s, int t)
{
	ElemType R1[LIST_INIT_SIZE +1];
	if (s < t)
	{
		int mid = (s + t) / 2;  //等分成两部分
		MergeSort(R, s, mid);  //对前半部分递归调用
		MergeSort(R, mid + 1, t);  //对后半部分递归调用
		Merge(R, R1, s, mid, t);  //合并两有序表
	}

}


int main()
{
	int i;
	/*int a,b;
	a = compute2n(3);
	std::cout << "the result of 2^n is "<<a << std::endl;

	Sqlist L ;
	List_Init( &L);
	for (i = 0; i < LIST_INIT_SIZE; i++)
	{
		std::cin >> L.elem[i];
	}*/
	/*for (int i = 0; i < LIST_INIT_SIZE; i++)
	{
		std::cout << L.elem[i]<<std::endl;
	}*/
	/*ElemType key;
	std::cout << "whitch key do you want to look for: " << std::endl;
	std::cin >> key;
	//std::cout << "the location of " << key << " is " << BinSearch2(&L, LIST_INIT_SIZE - 1,0, key) << std::endl;
	std::cout << "the number of " << key << " is " << Bincountkey(&L, LIST_INIT_SIZE - 1, 0, key) << std::endl;*/

	ElemType a[LIST_INIT_SIZE + 1] = { 0 };
	for (i = 0; i < LIST_INIT_SIZE ; i++)
	{
		std::cin >> a[i];
	}
	MergeSort(a, 0,LIST_INIT_SIZE-1 );
	for (i = 0; i < LIST_INIT_SIZE; i++)
	{
		std::cout << a[i]<<" ";
	}
	std::cout << std::endl;
	return 0;
}