# include<stdio.h>
# include"hash.h"

int main()
{
	//π˛œ£≤Â»Î”Î≤È’“≤‚ ‘
	HashTable H;
	int data[5] = { 1,3,7,5,0 };
	int i;
	RECORD R[5];
	int time, pos;
	for (i = 0; i < 5; i++)
	{
		R[i].key = data[i];
	}
	for (i = 0; i < 5; i++)
	{
		InsertHash(&H, R[i]);
	}
	SearchHash(H, 7, &pos, &time);
	printf("spend %d time find it in position %d\n", time+1, pos);
}