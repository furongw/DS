#include <stdlib.h>
#ifndef HUFFMAN
#define HUFFMAN
#define MAXBIT 8  //������󳤶�
#define MAXVALUE 10000

/*��Ž��Ľṹ��
HT[1,...,m] of Hnode ,m = 2n-1ǰn��ΪҶ������һ��Ϊ���ڵ�*/

typedef struct HNode
{
	int weight;
	int parent, lchild, rchild;
}HNode;

//��start = k����ַ����볤��Ϊn-k����������HCode�Ĵ�k+1��n�ķ����С�
typedef struct HCode  //����������ṹ
{
	int bit[MAXBIT];
	int start;
}HCode;

void HuffmanCoding(HNode* HT, HCode* HC, int* w, int n)
{
	//*w���n���ַ���Ȩֵ
	/*��ʼ��HT����*/
	int m,i;
	HNode* p;
	if (n <= 1)
	{
		return;
	}
	m = 2 * n - 1;  //һ��Ҷ���Ϊn�Ĺ���������2n-1�����
	//HT = (HNode*)malloc(m * sizeof(HNode));
	
	for (p = HT, i = 0; i < n; ++i, ++p, ++w)  //��ʼ��Ҷ���1��n
	{
		(*p).weight = *w;
		(*p).lchild = -1;
		(*p).rchild = -1;
		(*p).parent = -1;

	}

	//��ʼ����֧�ڵ�n+1��m
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
	/*�����������*/
	for (i = n; i < m; ++i)
	{
		//Ѱ�Ҹ����Ȩֵ��С�ĺʹ�С����������
		m1 = m2 = MAXVALUE;  //�����С�ʹ�С��ֵ
		x1 = x2 = 0;  //�����С�ʹ�С��λ��
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
	/*�ַ�����*/
	int start;
	int c,f;  //�ֱ��¼���½��͵��½���˫��
	//HC = (HCode*)malloc(n * sizeof(HCode));
	for (i = 0; i < n; ++i)  //�Ե�1����n���ַ�����
	{
		start = n - 1;
		c = i;
		f = HT[i].parent;
		for (; f != -1;)  //�Ӹ���i��һֱ���뵽Ҷ���
		{
			if (HT[f].lchild == c)  //�����ǰ�����˫�׵����ӱ���0
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
		HC[i].start = start + 1;  //��¼�������ʼλ��
	}
	
}


#endif // !huffman
