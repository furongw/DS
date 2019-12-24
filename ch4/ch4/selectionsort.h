#ifndef SELECTIONSORT
#define SELECTIONSORT

typedef struct DataType
{
	int key;
}DataType;

void Simple_Select_Sort(DataType R[], int n)
{
	//��R[1...n]����������
	int i,j,k;
	for (i = 1; i < n; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)
		{
			if (R[j].key < R[k].key)
			{
				k = j;  //�ұ��˹ؼ�����С�ļ�¼
			}
		}
		if (i != k)  //��С��¼��Ϊi���򽻻�
		{
			R[0] = R[k];
			R[k] = R[i];
			R[i] = R[0];
		}
	}
}
#endif // !SELECTIONSORT
