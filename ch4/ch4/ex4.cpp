#include <stdio.h>
#include <stdlib.h>


//练习4  设计算法按先序次序输出各节点的值及响应的层次数，并以二元组的形式给出
typedef int Datatype;

//树的存储结构
//二叉链表
typedef struct BiTreeNode
{
	Datatype data;  //数据
	struct BiTreeNode* lchild;  //左孩子
	struct BiTreeNode* rchild;  //右孩子
}BiTreeNode, * BiTree;

void initfullbintree(BiTree* p, int layer, Datatype data)
{
	BiTree now;
	if (layer == 0)
	{
		*p = NULL;
		return;
	}
	else
	{
		*p = (BiTree)malloc(sizeof(BiTreeNode));
		now = *p;
		now->data = data;
		initfullbintree(&now->lchild, layer - 1, 2 * data);
		initfullbintree(&now->rchild, layer - 1, 2 * data + 1);
	}
}

void visit(Datatype data,int layer)
{
	printf("(%d,%d)", data,layer);
}



//前序遍历
void PreOrder(BiTree bt, int layer)
{
	//layer指示当前层数，初始值为1
	if (bt != NULL)
	{
		visit(bt->data,layer);  ////访问函数依据实际情况填入
		PreOrder(bt->lchild,layer+1);
		PreOrder(bt->rchild,layer);
	}
}

int main()
{
	BiTreeNode node;
	BiTree p = &node;
	int i;

	//初始化一棵满二叉树
	initfullbintree(&p, 4, 1);

	printf("preorder:\n");
	PreOrder(p,0);
}