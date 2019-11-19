#include <stdio.h>
#include "huffman.h"

#define NUMSIZE 5

int main()
{
	int w[NUMSIZE] = { 18,293,1,20,49};
	int n = NUMSIZE;
	int m = 2 * NUMSIZE - 1;
	HNode* HT = (HNode*)malloc(m * sizeof(HNode));  //´æ·ÅÊ÷
	HCode* HC = (HCode*)malloc(n * sizeof(HCode));  //´æ·Å±àÂë
	HuffmanCoding(HT, HC, w, NUMSIZE);

	//¶ÁÈ¡±àºÅ
	int i;
	int start,j;
	for (i = 0; i < NUMSIZE; i++)
	{
		printf("the huffman code of number %d is: \n", w[i]);
		start = HC[i].start;
		for (j = NUMSIZE-1;j >= start; j--)
		{
			printf("%d", HC[i].bit[j]);
		}
		printf("\n");
	}
}