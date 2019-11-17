#include <iostream>

void move(char from, char to)
{
	//将from柱最上方的圆盘移到to柱
	std::cout << "move " << from << " column " << "to " << to <<" column"<< std::endl;
}


void hanio(int n, char from, char to, char mid1, char mid2)
{
	if (n == 1)
	{
		move(from, to);//将唯一一个圆盘移到第四个柱子
	}
	else if (n == 2)  //仅有两个圆盘
	{
		move(from,mid1);
		move(from, to);
		move(mid1,to);
	}
	else  //递归调用
	{
		hanio(n - 2,from,mid1,mid2,to);  //n-2个经由mid2和to到mid1
		move(from,mid2);  //倒数第二大到mid2
		move(from,to);  //倒数第一大到to
		move(mid2,to);  //倒数第二大到to
		hanio(n - 2,mid1,to,from,mid2);  //前n-2个经由from和mid2到to
	}
}

int main()
{
	hanio(4,'a','d','b','c');
}