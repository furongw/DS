#include <iostream>

void move(char from, char to)
{
	//��from�����Ϸ���Բ���Ƶ�to��
	std::cout << "move " << from << " column " << "to " << to <<" column"<< std::endl;
}


void hanio(int n, char from, char to, char mid1, char mid2)
{
	if (n == 1)
	{
		move(from, to);//��Ψһһ��Բ���Ƶ����ĸ�����
	}
	else if (n == 2)  //��������Բ��
	{
		move(from,mid1);
		move(from, to);
		move(mid1,to);
	}
	else  //�ݹ����
	{
		hanio(n - 2,from,mid1,mid2,to);  //n-2������mid2��to��mid1
		move(from,mid2);  //�����ڶ���mid2
		move(from,to);  //������һ��to
		move(mid2,to);  //�����ڶ���to
		hanio(n - 2,mid1,to,from,mid2);  //ǰn-2������from��mid2��to
	}
}

int main()
{
	hanio(4,'a','d','b','c');
}