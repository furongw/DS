#include <stdio.h>
#include "selectionsort.h"

int main()
{
	DataType R[7+1];
	int data[7] = { 6,15,45,23,9,78,35 };
	int i;
	for (i = 1; i <= 7; i++)
	{
		R[i].key = data[i-1];
	}
	Simple_Select_Sort(R, 7);
	for (i = 1; i <= 7; i++)
	{
		printf("%d ", R[i].key);
	}
}