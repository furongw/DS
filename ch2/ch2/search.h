#ifndef SEARCH
#define SEARCH

# include "../../ch1/ch1/all.h"
typedef struct DataType
{
	Datatype data;
	int key;
}DataType;

//˳�����
int seqsearch(DataType R[], int n, Datatype key)
{
	int i = n;
	R[0].key = key;  //R[0]������
	while (R[i].key != key)
	{
		i--;
	}
	return i;
}

typedef struct IndexType
{
	Datatype key;  //�ؼ�����
	int Link;  //ָ����
}IndexType;

//�������˳������㷨
int IndexSequelSearch(IndexType ls[], DataType s[], int m, Datatype key)
{
	//������Ϊls[0]-ls[m-1]��˳���Ϊs[]
	int i;
	i = 0;
	int j;
	while (i<m && key >ls[i].key)  //������
	{
		i++;
	}
	if (i == m)  //����ʧ��
	{
		return -1;
	}
	else
	{
		j = ls[i].Link;
		while (key != s[j].key && j < ls[i + 1].Link)
		{
			j++;
		}
		if (key == s[j].key)
		{
			return j;  //���ҳɹ�
		}
		else return -1;  //����ʧ��
	}
}
#endif // !SEARCH
