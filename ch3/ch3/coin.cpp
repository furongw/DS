#include <iostream>

#define ARRAY_SIZE 3



int findcoin(int total, int coin[],int min, int coincount[])
{
	/*ʵ�ָ�����Ϊtotal����Ǯ��coin[]Ϊ��Ǯ���ϣ�minΪ��С��Ǯ��coincountΪ��Ӧ��Ǯ���������Ǯ��*/
	int i;
	if (total < min)  //���totalС����С���޽�
	{
		return 0;
	}
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		if (total == coin[i])  //���total����ĳ����Ǯ���ɹ�����Ӧcount++
		{
			coincount[i]++;
			//std::cout << "coin " << coin[i];
			return 1;
		}
		if (findcoin(total - coin[i], coin, min,coincount))  //�ݹ�Ѱ�Ҽ�ȥ����������Ǯ����ܶ����Ǯ
		{
			coincount[i]++;
			//std::cout << "coin " << coin[i];
			return 1;
		}
	}
	return 0;
	//���㷨�е����Ǳ�������ˣ�ʱ�临�ӶȺܸߣ�ֻѰ�ҵ�һ�ֽ���ͷ���
}


int main()
{
	int coin[ARRAY_SIZE] = {7,3,2};  //Ӳ�Ҽ���
	int coincount[ARRAY_SIZE] = { 0 };  //��ӦӲ����Ŀ
	int i;
	int min = coin[0];  //����СӲ��
	for (i = 0; i < ARRAY_SIZE; i++)
	{
		if (coin[i] < min)
		{
			min = coin[i];
		}
	}
	if (findcoin(24, coin, min, coincount)==1)
	{
		for (i = 0; i < ARRAY_SIZE; i++)
		{
			std::cout << "the number of coin " << coin[i] << " is " << coincount[i] << std::endl;  //���
		}
	}
	else
	{
		std::cout << "no way" << std::endl;
	}
}