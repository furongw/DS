#ifndef SEARCH
#define SEARCH

# include "../../ch1/ch1/all.h"
typedef struct DataType
{
	Datatype data;
	int key;
}DataType;

//顺序查找
int seqsearch(DataType R[], int n, Datatype key)
{
	int i = n;
	R[0].key = key;  //R[0]监视哨
	while (R[i].key != key)
	{
		i--;
	}
	return i;
}

typedef struct IndexType
{
	Datatype key;  //关键字项
	int Link;  //指针项
}IndexType;

//索引表的顺序查找算法
int IndexSequelSearch(IndexType ls[], DataType s[], int m, Datatype key)
{
	//索引表为ls[0]-ls[m-1]，顺序表为s[]
	int i;
	i = 0;
	int j;
	while (i<m && key >ls[i].key)  //块间查找
	{
		i++;
	}
	if (i == m)  //查找失败
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
			return j;  //查找成功
		}
		else return -1;  //查找失败
	}
}
#endif // !SEARCH
