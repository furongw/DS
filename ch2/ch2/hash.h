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
	RECORD data[TABLESIZE] = {};  //��ʼ��Ϊ��
}HashTable;

int Hash(int key)
{
	return key % TABLESIZE;
}

//��ͻ��̽�⺯��
void collision(int* p, int *c)
{
	*p += 1;
	*c += 1;
}

Status SearchHash(HashTable H, Datatype key, int* p, int* c)
{
	//�ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���Ϊkey������
	//�����ҳɹ�����pָʾ���������ڱ��е�λ�ã�������SUCCESS��������pָʾ����λ�ã�������false
	//��c��¼������ͻ�Ĵ�������ֵΪ0
	Status status = fail;
	*p = Hash(key);  //���ϣ��ַ
	*c = 0;
	while (H.data[*p].key != NULL && H.data[*p].key != key)
	{
		//��λ������������������ؼ��ֲ�ͬ
		collision(p, c);  //����һ̽���ַ
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

//��ϣ�����㷨
Status InsertHash(HashTable *HT, RECORD e)
{
	//���Ҳ��ɹ�ʱ����H�в�������Ԫ��e��������SUCCESS
	//����ͻ�����������ؽ���ϣ��
	Status status = fail;
	int c = 0;
	int p;
	HashTable H = *HT;
	if (SearchHash(H, e.key, &p, &c))
	{
		return fail;  //�������ڹ�ϣ���У��������
	}
	else if (c < MAXTIME)  //���Ҵ���δ������,����
	{
		H.data[p] = e;
		return success;
	}
	/*
	else
	{
		RecreateHashTable(H);  //�ؽ���ϣ��
		return fail;
	}
	*/
	return status;
}
#endif // !HASH
