/*第三章  递归与分治 */


#include <stdio.h>
#include <iostream>
#include "recursion.h"
#include "../../ch1/ch1/all.h"


int main()
{
	int i;
	/*int a,b;
	a = compute2n(3);
	std::cout << "the result of 2^n is "<<a << std::endl;

	Sqlist L ;
	List_Init( &L);
	for (i = 0; i < LIST_INIT_SIZE; i++)
	{
		std::cin >> L.elem[i];
	}*/
	/*for (int i = 0; i < LIST_INIT_SIZE; i++)
	{
		std::cout << L.elem[i]<<std::endl;
	}*/
	/*ElemType key;
	std::cout << "whitch key do you want to look for: " << std::endl;
	std::cin >> key;
	//std::cout << "the location of " << key << " is " << BinSearch2(&L, LIST_INIT_SIZE - 1,0, key) << std::endl;
	std::cout << "the number of " << key << " is " << Bincountkey(&L, LIST_INIT_SIZE - 1, 0, key) << std::endl;*/


	Datatype a[LIST_INIT_SIZE + 1] = { 0 };
	for (i = 0; i < LIST_INIT_SIZE ; i++)
	{
		std::cin >> a[i];
	}
	MergeSort(a, 0,LIST_INIT_SIZE-1 );
	for (i = 0; i < LIST_INIT_SIZE; i++)
	{
		std::cout << a[i]<<" ";
	}
	std::cout << std::endl;
	return 0;

}