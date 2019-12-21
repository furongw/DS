#include <stdio.h>
# include "search.h"

int main()
{
	//≤‚ ‘À≥–Ú≤È’“
	DataType R[5+1];
	int i;
	int pos;
	for (i = 1; i <= 5; i++)
	{
		R[i].key = i;
	}
	pos = seqsearch(R, 5, 3);
	printf("seq search pos: %d\n", pos);

	//≤‚ ‘À˜“˝≤È’“
	DataType S[18 + 1];
	int data[] = {22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
	IndexType Is[3];
	for (i = 1; i <= 18; i++)
	{
		S[i].key = data[i - 1];
	}
	Is[0].key = 22;
	Is[0].Link = 1;
	Is[1].key = 48;
	Is[1].Link = 7;
	Is[2].key = 86;
	Is[2].Link= 13;
	pos = IndexSequelSearch(Is, S, 3, 42);
	printf("Indexsearch pos: %d", pos);
}