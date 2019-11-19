/*������  �ݹ������ */


#include <stdio.h>
#include <iostream>
#include "../../../Project2/Project2/algo_seqlist.h"


//2�׳�
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

//���ֲ���(�ݹ�ʵ��)
int BinSearch(ListPtr L, int high, int low, ElemType key)
{
	//�������L�в��ҹؼ���Ϊkey��Ԫ��
	//�����ڣ�����ҳɹ�����������������е�λ�ã����򣬲���ʧ�ܣ�����-1
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

//���ֲ���(�ǵݹ�ʵ��)
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

/*ʵ�ֲ���������е���k��Ԫ�ص���Ŀ��������򷵻�-1*/
//Ѱ���±߽����
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

//Ѱ���ϱ߽��Ҳ�
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
	//����Ѱ�ҵ�key����Ŀ
	return BinSearchhigh(L, high, low, key) - BinSearchlow(L, high, low, key) - 1;
}


/*ð��������Ľ�*/
void BubbleSort(ElemType *R, int n)
{
	//�Գ���Ϊn������R���������ð������
	int i, j, swap;
	for (i = 0; i < n ; i++)
	{
		swap = 0;  //������־
		for (j = 0; j <= n  - i; j++)
		{
			if (R[j] > R[j + 1])  //���������򣬽���
			{
				R[n] = R[j + 1];  //�������һ���洢��Ԫ��Ϊ����λ����ʵ�������׽̲�Ϊʲô��Ҫ�����������Ԫ��������λ���������ӳ���ķ������
				R[j + 1] = R[j];  //����ԭΪ������һ��Ԫ�أ������Ҹ���
				R[j] = R[n];
				swap = 1;
			}
			
		}
		if (swap == 0) break;
	}

}

/*ð������ĸĽ�*/

void swap(ElemType* a, ElemType* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//��¼�����һ�ν���
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

/*��������*/
//���Σ����ػ���ԪӦ�ڵ�λ��
int Partition(ElemType R[], int low, int high)
{
	ElemType pivot = R[low];
	while (low < high)
	{
		while (low < high && R[high] >= pivot)
		{
			high--;
		}
		R[low] = R[high];  //С�ڻ���Ԫ�ص�Ԫ�ؽ������Ͷ�
		while (low < high && R[low] <= pivot)
		{
			low++;
		}
		R[high] = R[low];  //���ڻ���Ԫ�ص�Ԫ�ؽ������߶�
	}
	R[low] = pivot;  //����Ԫ������ȷλ��
	return low;  //���ػ���Ԫλ��
}

//�ݹ���ÿ���
void QuickSort(ElemType R[], int low, int high)
{
	if (low < high)
	{
		int pivot_position = Partition(R, low, high);
		QuickSort(R, low, pivot_position - 1);
		QuickSort(R, pivot_position + 1, high);
	}
}

/*�鲢����*/
void Merge(ElemType R[], ElemType R1[], int s, int mid, int t)
{
	//��R[s...t]��������R[s..mid]��R[mid+1..t]�Ѱ��ؼ�������
	//��R[s..mid]��R[mid+1..t]�ϲ��������R1[s..t]
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
		int mid = (s + t) / 2;  //�ȷֳ�������
		MergeSort(R, s, mid);  //��ǰ�벿�ֵݹ����
		MergeSort(R, mid + 1, t);  //�Ժ�벿�ֵݹ����
		Merge(R, R1, s, mid, t);  //�ϲ��������
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