#ifndef RECURSION
# define RECURSION
# include "../../ch1/ch1/all.h"
# include "../../ch2/ch2/sqlist.h"
#define LIST_INIT_SIZE 7  //�����ʼ������
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
int BinSearch(ListPtr L, int high, int low, Datatype key)
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
int BinSearch2(ListPtr L, int high, int low, Datatype key)
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
int BinSearchlow(ListPtr L, int high, int low, Datatype key)
{
	int mid;
	if (low > high)
	{
		return low - 1;
	}
	mid = (high + low) / 2;
	if (L->elem[mid] >= key)
	{
		return BinSearchlow(L, mid - 1, low, key);
	}
	else
	{
		return BinSearchlow(L, high, mid + 1, key);
	}
}

//Ѱ���ϱ߽��Ҳ�
int BinSearchhigh(ListPtr L, int high, int low, Datatype key)
{
	int mid;
	if (high < low)
	{
		return low;
	}
	mid = (high + low) / 2;
	if (L->elem[mid] > key)
	{
		return BinSearchhigh(L, mid - 1, low, key);
	}
	else
	{
		return BinSearchhigh(L, high, mid + 1, key);
	}
}

int Bincountkey(ListPtr L, int high, int low, Datatype key)
{
	//����Ѱ�ҵ�key����Ŀ
	return BinSearchhigh(L, high, low, key) - BinSearchlow(L, high, low, key) - 1;
}


/*ð��������Ľ�*/
void BubbleSort(Datatype* R, int n)
{
	//�Գ���Ϊn������R���������ð������
	int i, j, swap;
	for (i = 0; i < n; i++)
	{
		swap = 0;  //������־
		for (j = 0; j <= n - i; j++)
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

void swap(Datatype* a, Datatype* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//��¼�����һ�ν���
void BubbleSort2(Datatype R[], int n)
{
	int i, j, lastExchangeIndex;
	i = n;
	while (i > 0)
	{
		lastExchangeIndex = 0;
		for (j = 0; j < i; j++)
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
int Partition(Datatype R[], int low, int high)
{
	Datatype pivot = R[low];
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
void QuickSort(Datatype R[], int low, int high)
{
	if (low < high)
	{
		int pivot_position = Partition(R, low, high);
		QuickSort(R, low, pivot_position - 1);
		QuickSort(R, pivot_position + 1, high);
	}
}

/*�鲢����*/
void Merge(Datatype R[], Datatype R1[], int s, int mid, int t)
{
	//��R[s...t]��������R[s..mid]��R[mid+1..t]�Ѱ��ؼ�������
	//��R[s..mid]��R[mid+1..t]�ϲ��������R1[s..t]
	int k, i, j;
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

void MergeSort(Datatype R[], int s, int t)
{
	Datatype R1[LIST_INIT_SIZE + 1];
	if (s < t)
	{
		int mid = (s + t) / 2;  //�ȷֳ�������
		MergeSort(R, s, mid);  //��ǰ�벿�ֵݹ����
		MergeSort(R, mid + 1, t);  //�Ժ�벿�ֵݹ����
		Merge(R, R1, s, mid, t);  //�ϲ��������
	}

}
#endif // !RECURSION
