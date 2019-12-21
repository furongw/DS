#include "insertsort.h"
#include <stdio.h>

int main()
{
	//≤‚ ‘÷±Ω”≤Â»Î≈≈–Ú
	int data[10] = { 0,9,2,5,10,23,11,7,996,17 };
	DataType R[10] ;
	int i;
	for (i = 0; i < 10; i++)
	{
		R[i].key = data[i];
	}
	//Direct_Insert_Sort(R, 9);
	printf("direct insert sort:\n");
	for (i = 1; i < 10; i++)
	{
		printf("%d ", R[i].key);
	}
	printf("\n");

	//≤‚ ‘’€∞Î≤Â»Î≈≈–Ú
	//BInsertSort(data, 10);
	printf("binsertsort:\n");
	for (i = 1; i < 10; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");

	//≤‚ ‘œ£∂˚≈≈–Ú
	printf("ShellSort:\n");
	int seq[] = { 7,5,3,1 };
	Shell_Insert_Sort(R, 9, seq, 4);
	for (i = 1; i < 10; i++)
	{
		printf("%d ", R[i].key);
	}
	printf("\n");

}