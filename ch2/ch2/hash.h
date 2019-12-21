#ifndef HASH
#define HASH
# include "../../ch1/ch1/all.h"
#include <cstddef>
#define TABLESIZE 7
#define MAXTIME 10

typedef struct RECORD
{
	Datatype key;
};

typedef struct HashTable
{
	RECORD data[TABLESIZE] = {};  //初始化为空
}HashTable;

int Hash(int key)
{
	return key % TABLESIZE;
}

//冲突重探测函数
void collision(int* p, int *c)
{
	*p += 1;
	*c += 1;
}

Status SearchHash(HashTable H, Datatype key, int* p, int* c)
{
	//在开放定址哈希表H中查找关键字为key的数据
	//若查找成功，以p指示待查数据在表中的位置，并返回SUCCESS；否则，以p指示插入位置，并返回false
	//用c记录发生冲突的次数，初值为0
	Status status = fail;
	*p = Hash(key);  //求哈希地址
	*c = 0;
	while (H.data[*p].key != NULL && H.data[*p].key != key)
	{
		//该位置填有数据且与所查关键字不同
		collision(p, c);  //求下一探查地址
	}
	if (H.data[*p].key == key)
	{
		return success;
	}
	else
	{
		return status;
	}
}

//哈希插入算法
Status InsertHash(HashTable *HT, RECORD e)
{
	//查找不成功时，在H中插入数据元素e，并返回SUCCESS
	//若冲突次数过大，则重建哈希表
	Status status = fail;
	int c = 0;
	int p;
	HashTable H = *HT;
	if (SearchHash(H, e.key, &p, &c))
	{
		return fail;  //数据已在哈希表中，不需插入
	}
	else if (c < MAXTIME)  //查找次数未达上限,插入
	{
		H.data[p] = e;
		return success;
	}
	/*
	else
	{
		RecreateHashTable(H);  //重建哈希表
		return fail;
	}
	*/
	return status;
}
#endif // !HASH
