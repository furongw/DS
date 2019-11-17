#ifndef TREE
#define TREE
#include <cstddef>
#include <stdio.h>
#include <malloc.h>
typedef int Datatype;  //�������ݸ�ʽ
#define MAX_TREE_SIZE 100

//���Ĵ洢�ṹ
//��������
typedef struct BiTreeNode
{
	Datatype data;  //����
	struct BiTreeNode* lchild;  //����
	struct BiTreeNode* rchild;  //�Һ���
}BiTreeNode,*BiTree;

//��������
typedef struct TriTreeNode
{
	Datatype data;
	struct TriTreeNode* lchild, * rchild, * parent;  //���ӣ��Һ��ӣ�˫��
}TriTreeNode,*TriTree;


/*�洢�ṹ*/
//����˫�ױ�ʾ��
typedef struct PTNode
{
	Datatype data;
	int parent;
}PTNode;

typedef struct PTree
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;
}PTree;

//���ĺ��ӱ�ʾ��
typedef struct CTNode
{
	int child;
	struct CTNode* next;
}CTBox;

typedef struct CTree
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;
}CTree;

//����˫�׺��ӱ�ʾ��

//���ĺ����ֵܱ�ʾ��
typedef struct CSNode
{
	Datatype data;
	struct CSNode* firstchild, * nextsibling;  //��һ�����ӽ�����һ���ֵܽ��
}CSNode;

/*���ı�����ǰ�����򡢺���*/

void visit(Datatype data)
{
	printf("%d ", data);
}



//ǰ�����
void PreOrder(BiTree bt)
{
	if (bt != NULL)
	{
		visit(bt->data);  ////���ʺ�������ʵ���������
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

//�������
void InOrder(BiTree bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		visit(bt->data);
		InOrder(bt->rchild);
	}
}

//�������
void PostOrder(BiTree bt)
{
	if (bt != NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		visit(bt->data);
	}
}

//��������ķǵݹ��㷨
void NRInOrder(BiTree bt)
{
	BiTree S[MAX_TREE_SIZE], p = bt;
	int top = -1;  //����ջs���ƶ�ָ��p������ʼ��Ϊ��ջ
	while (!(p == NULL && top == -1))  //p�պ�ջͬʱ�ս���
	{
		while (p)  //������˽�㣬��;�����Ľ����ջ
		{
			if (top < MAX_TREE_SIZE - 1)
			{
				S[++top] = p;
				p = p->lchild;
			}
			else
			{
				printf("ջ���\n");
				return;
			}

		}
		if (top == -1)
		{
			return;
		}
		else
		{
			p = S[top--];
			visit(p->data);
			p = p->rchild;
		}
	}
}

//�������Ĳ�α���
void LevelOrder(BiTree bt)
{
	BiTree Queue[MAX_TREE_SIZE];  //�������
	int front = -1;
	int rear = 0;
	if (!bt)  //�ն���������������
	{
		return;
	}
	Queue[rear] = bt;  //���ڵ������
	while (rear != front)  //���в��գ���������
	{
		front++;  
		visit(Queue[front]->data);
		if (Queue[front]->lchild !=NULL)  //��������ӣ��������
		{
			rear++;
			Queue[rear] = Queue[front]->lchild;
		}
		if (Queue[front]->rchild!=NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->rchild;
		}
	}
}

/*��֪�������������������������һ�ö�����*/
void PreInOrd(Datatype preord[], Datatype inord[], int i, int j, int k, int h, BiTree* t)
{
	//���������i��j�������д�k��h������һ�ö���������t
	int m = k;
	*t = (BiTree)malloc(sizeof(BiTreeNode));
	BiTree bt;
	bt = *t;
	bt->data = preord[i];  //�������ĸ�
 	while (inord[m] != preord[i])
	{
		m++;  //�����������ж�λ����
	}
	//�ݹ���ý���������
	if (m == k)  //������Ϊ��
	{
		bt->lchild = NULL;
	}
	else
	{
		PreInOrd(preord, inord, i + 1, i + m - k, k, m - 1, &bt->lchild);
	}
	//�ݹ���ý���������
	if (m == h)  //��������
	{
		bt->rchild = NULL;
	}
	else
	{
		PreInOrd(preord, inord, i + m - k + 1, j, m + 1, h, &bt->rchild);
	}
}

void CreateBiTree(Datatype preord[], Datatype inord[], int n, BiTree* root)
{
	//nΪ���������ĸ����������Ķ���������root��
	if (n <= 0)
	{
		*root = NULL;
	}
	else
	{
		*root = (BiTree)malloc(sizeof(BiTreeNode));
		PreInOrd(preord, inord, 0, n-1, 0, n-1, root);
	}
}

//һ������һ�������ܵõ�������������������е��㷨
void XOrder(BiTree bt)
{
	if (bt != NULL)
	{
		visit(bt->data);
		XOrder(bt->lchild);
		visit(bt->data);
		XOrder(bt->rchild);
		visit(bt->data);
	}
}

/*�����㷨��Ӧ��*/
//ͳ�ƶ�������Ҷ������
int BitreeLeaf(BiTree bt)
{
	if (bt == NULL)return 0;
	if (bt->lchild==NULL && bt->rchild == NULL)
	{
		return 1;
	}
	return (BitreeLeaf(bt->lchild) + BitreeLeaf(bt->rchild));
}

//�����������
int BitreeDepth(BiTree bt)
{
	int dL, dR,sontreedepth;
	if (!bt)
	{
		return 0;
	}
	if (!bt->lchild && !bt->rchild)  //Ҷ������Ϊ1
	{
		return 1;
	}
	dL = BitreeDepth(bt->lchild);  //���������
	dR = BitreeDepth(bt->rchild);  //���������
	sontreedepth = (dL > dR) ? dL : dR;
	return 1 +sontreedepth;
}

//�ж���ȫ�������㷨�����һ��������queue2
int LevelOrder3(BiTree bt)
{
	BiTree Queue[MAX_TREE_SIZE];
	int Que2[MAX_TREE_SIZE];
	int front = 0, rear = 1, front2 = 0, rear2 = 1;
	if (bt == NULL)
	{
		return 1;
	}
	Queue[rear] = bt;
	Que2[rear2] = 1;
	while (rear != front)
	{
		front++;
		if (Que2[front]== front)
		{
			visit(Queue[front]->data);
			if (Queue[front]->lchild != NULL)
			{
				rear++;
				Queue[rear] = Queue[front]->lchild;
				rear2++;
				Que2[rear2] = 2 * front;
			}
			if (Queue[front]->rchild != NULL)
			{
				rear++;
				Queue[rear] = Queue[front]->rchild;
				rear2++;
				Que2[rear2]= 2 * front + 1;
			}
		}
		else return 0;
	}
	return 1;
}

#endif // TREE

