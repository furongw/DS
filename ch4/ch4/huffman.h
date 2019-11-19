#include <stdlib.h>
#ifndef HUFFMAN
#define HUFFMAN
#define MAXBIT 8  //编码最大长度
#define MAXVALUE 10000

/*存放结点的结构：
HT[1,...,m] of Hnode ,m = 2n-1前n个为叶结点最后一个为根节点*/

typedef struct HNode
{
	int weight;
	int parent, lchild, rchild;
}HNode;

//若start = k则该字符编码长度为n-k，编码存放在HCode的从k+1到n的分量中。
typedef struct HCode  //哈夫曼编码结构
{
	int bit[MAXBIT];
	int start;
}HCode;

void HuffmanCoding(HNode* HT, HCode* HC, int* w, int n)
{
	//*w存放n个字符的权值
	/*初始化HT向量*/
	int m,i;
	HNode* p;
	if (n <= 1)
	{
		return;
	}
	m = 2 * n - 1;  //一棵叶结点为n的哈夫曼树有2n-1个结点
	//HT = (HNode*)malloc(m * sizeof(HNode));
	
	for (p = HT, i = 0; i < n; ++i, ++p, ++w)  //初始化叶结点1到n
	{
		(*p).weight = *w;
		(*p).lchild = -1;
		(*p).rchild = -1;
		(*p).parent = -1;

	}

	//初始化分支节点n+1到m
	for (; i < m; ++i, ++p)
	{
		(*p).weight = 0;
		(*p).lchild = -1;
		(*p).rchild = -1;
		(*p).parent = -1;
	}
	int m1, m2;
	int x1, x2;
	int j;
	/*构造哈夫曼树*/
	for (i = n; i < m; ++i)
	{
		//寻找根结点权值最小的和次小的两颗子树
		m1 = m2 = MAXVALUE;  //存放最小和次小的值
		x1 = x2 = 0;  //存放最小和次小的位置
		for (j = 0; j < i;++j)
		{
			if (HT[j].parent == -1 && HT[j].weight < m1)
			{
				m2 = m1;
				m1 = HT[j].weight;
				x2 = x1;
				x1 = j;
			}
			else if (HT[j].parent == -1 && HT[j].weight < m2)
			{
				m2 = HT[j].weight;
				x2 = j;
			}
			
		}
		HT[x1].parent = i;
		HT[x2].parent = i;
		HT[i].lchild = x1;
		HT[i].rchild = x2;
		HT[i].weight = m1 + m2;
		HT[i].parent = -1;
	}
	/*字符编码*/
	int start;
	int c,f;  //分别记录当下结点和当下结点的双亲
	//HC = (HCode*)malloc(n * sizeof(HCode));
	for (i = 0; i < n; ++i)  //对第1到第n个字符编码
	{
		start = n - 1;
		c = i;
		f = HT[i].parent;
		for (; f != -1;)  //从根（i）一直编码到叶结点
		{
			if (HT[f].lchild == c)  //如果当前结点是双亲的左孩子编码0
			{
				HC[i].bit[start--] = 0;  
			}
			else
			{
				HC[i].bit[start--] = 1;
			}
			c = f;
			f = HT[f].parent;
		}
		HC[i].start = start + 1;  //记录编码的起始位置
	}
	
}


#endif // !huffman
