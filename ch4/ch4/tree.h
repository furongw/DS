#ifndef TREE
#define TREE
#include <cstddef>
#include <stdio.h>
#include <malloc.h>
typedef int Datatype;  //定义数据格式
#define MAX_TREE_SIZE 100

//树的存储结构
//二叉链表
typedef struct BiTreeNode
{
	Datatype data;  //数据
	struct BiTreeNode* lchild;  //左孩子
	struct BiTreeNode* rchild;  //右孩子
}BiTreeNode,*BiTree;

//三叉链表
typedef struct TriTreeNode
{
	Datatype data;
	struct TriTreeNode* lchild, * rchild, * parent;  //左孩子，右孩子，双亲
}TriTreeNode,*TriTree;


/*存储结构*/
//树的双亲表示法
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

//树的孩子表示法
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

//树的双亲孩子表示法

//树的孩子兄弟表示法
typedef struct CSNode
{
	Datatype data;
	struct CSNode* firstchild, * nextsibling;  //第一个孩子结点和下一个兄弟结点
}CSNode;

/*树的遍历：前序、中序、后序*/

void visit(Datatype data)
{
	printf("%d ", data);
}



//前序遍历
void PreOrder(BiTree bt)
{
	if (bt != NULL)
	{
		visit(bt->data);  ////访问函数依据实际情况填入
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

//中序遍历
void InOrder(BiTree bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		visit(bt->data);
		InOrder(bt->rchild);
	}
}

//后序遍历
void PostOrder(BiTree bt)
{
	if (bt != NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		visit(bt->data);
	}
}

//中序遍历的非递归算法
void NRInOrder(BiTree bt)
{
	BiTree S[MAX_TREE_SIZE], p = bt;
	int top = -1;  //定义栈s和移动指针p，并初始化为空栈
	while (!(p == NULL && top == -1))  //p空和栈同时空结束
	{
		while (p)  //找最左端结点，沿途遇到的结点入栈
		{
			if (top < MAX_TREE_SIZE - 1)
			{
				S[++top] = p;
				p = p->lchild;
			}
			else
			{
				printf("栈溢出\n");
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

//二叉树的层次遍历
void LevelOrder(BiTree bt)
{
	BiTree Queue[MAX_TREE_SIZE];  //定义队列
	int front = -1;
	int rear = 0;
	if (!bt)  //空二叉树，遍历结束
	{
		return;
	}
	Queue[rear] = bt;  //根节点入队列
	while (rear != front)  //队列不空，继续遍历
	{
		front++;  
		visit(Queue[front]->data);
		if (Queue[front]->lchild !=NULL)  //如果有左孩子，左孩子入队
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

/*已知先序遍历和中序遍历结果，创建一棵二叉树*/
void PreInOrd(Datatype preord[], Datatype inord[], int i, int j, int k, int h, BiTree* t)
{
	//先序遍历从i到j中序序列从k到h，建立一棵二叉树放在t
	int m = k;
	*t = (BiTree)malloc(sizeof(BiTreeNode));
	BiTree bt;
	bt = *t;
	bt->data = preord[i];  //二叉树的根
 	while (inord[m] != preord[i])
	{
		m++;  //在中序序列中定位树根
	}
	//递归调用建立左子树
	if (m == k)  //左子树为空
	{
		bt->lchild = NULL;
	}
	else
	{
		PreInOrd(preord, inord, i + 1, i + m - k, k, m - 1, &bt->lchild);
	}
	//递归调用建立右子树
	if (m == h)  //右子树空
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
	//n为二叉树结点的个数，建立的二叉树放在root中
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

//一个遍历一次树就能得到先序中序后序三个序列的算法
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

/*遍历算法的应用*/
//统计二叉树中叶结点个数
int BitreeLeaf(BiTree bt)
{
	if (bt == NULL)return 0;
	if (bt->lchild==NULL && bt->rchild == NULL)
	{
		return 1;
	}
	return (BitreeLeaf(bt->lchild) + BitreeLeaf(bt->rchild));
}

//计算树的深度
int BitreeDepth(BiTree bt)
{
	int dL, dR,sontreedepth;
	if (!bt)
	{
		return 0;
	}
	if (!bt->lchild && !bt->rchild)  //叶结点深度为1
	{
		return 1;
	}
	dL = BitreeDepth(bt->lchild);  //左子树深度
	dR = BitreeDepth(bt->rchild);  //右子树深度
	sontreedepth = (dL > dR) ? dL : dR;
	return 1 +sontreedepth;
}

//判断完全二叉树算法，设计一辅助队列queue2
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

