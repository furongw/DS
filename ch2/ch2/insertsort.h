#ifndef INSERTSORT
#define INSERTSORT

typedef struct DataType
{
	int key;
}DataType;

void Direct_Insert_Sort(DataType R[], int n)
{
	//���ؼ����������У��ӵ�2����¼��ʼ��R[0]��Ϊ������
	int i,j;
	for (i = 2; i <= n; ++i)
	{
		if (R[i].key < R[i - 1].key)
		{
			R[0].key = R[i].key;
			for (j = i - 1; R[0].key < R[j].key; j--)//���򲿷����һ����ʼ��ǰ̽����ͬʱ����
			{
				R[j + 1] = R[j];
			}
			R[j + 1] = R[0];  //����¼���뵽��ȷλ��
		}
	}
}

//�۰��������
void BInsertSort(int a[], int size)
{
	int i, j,mid;
	int temp = 0;
	int low = 0;
	int high = 0;
	for (i = 1; i < size;i++)
	{
		low = 0;  //��ʼ��low���ʼΪ0
		high = i - 1;  //��ʼ��high,�ʼΪi-1��Ϊ�������������
		temp = a[i];  //�����۰���ҷ��жϲ���λ�ã����ձ���low��ʾ����λ��
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
		for (j = i; j > low; j--)  //������в���λ�ú��Ԫ��ͳһ����
		{
			a[j] = a[j - 1];
		}
		a[low] = temp;  //����Ԫ��
	}
}

//ϣ�������㷨
void Shell_Insert_Sort(DataType R[], int n, int d[], int t)
{
	int i, j, k, dk;
	//����������ΪR[1,...,n],d[0,...,t-1]Ϊ��������
	for (k = 0; k < t; k++)
	{
		dk = d[k];
		for (i = dk + 1; i <= n; ++i)  //��R[i]���뵽����������������
		{
			if (R[i].key < R[i - dk].key)
			{
				R[0] = R[i];  //������R[0]
				for (j = i - dk; j > 0 && R[0].key < R[j].key; j = j - dk)
				{
					R[j + dk] = R[j];  //Ѱ�Ҳ���λ�ã�ͬʱ���ݺ���
				}
				R[j + dk] = R[0];  //���뵽��ȷλ��
			}
		}
	}
}
#endif // !INSERTSORT
