#ifndef BINSORTREE
#define BINSORTREE


#include "tree.h"

//二叉排序树存储结构
typedef struct BSTNode
{
	int key;  //关键字域
	struct BSTNode* lchild, * rchild;//左右孩子指针
}BSTNode, * BSTree;

//二叉搜素/排序树的插入算法
BiTree Insert(Datatype x, BiTree &bst)
{
	if (!bst)  //若原树为空，生成并返回一个结点的二叉搜索树
	{
		bst = (BiTree)malloc(sizeof(BiTree));
		bst->data = x;
		bst->lchild = NULL;
		bst->rchild = NULL;
	}
	else
	{
		if (x < bst->data)
		{
			bst->lchild = Insert(x, bst->lchild);  //递归插入左子树
		}
		else if(x>bst->data)
		{
			bst->rchild = Insert(x, bst->rchild);  //递归插入右子树
		}
		//else x已存在，什么都不做
	}
	return bst;
}

//二叉排序树的搜索
BiTree Find(Datatype x, BiTree BST)
{
	if (!BST)
	{
		return NULL;//查找失败
	}
	if (x > BST->data)
	{
		return Find(x, BST->rchild);  //在右子树中继续查找
	}
	else if (x < BST->data)
	{
		return Find(x, BST->lchild);  //在左子树中继续查找
	}
	else //x==BST.data
	{
		return BST;  //查找成功，返回找到结点的地址
	}
}

//二叉排序树的非递归寻找法
BiTree IterFind(Datatype x, BiTree BST)
{
	while (BST)
	{
		if (x > BST->data)
		{
			BST = BST->rchild;  //向右子树中移动，继续查找
		}
		else if (x < BST->data)
		{
			BST = BST->lchild;  //向左子树中移动，继续查找
		}
		else  //x==BST.data
		{
			return BST;  //查找成功，返回结点的找到结点的地址
		}
	}
	return NULL;
}

//查找最大元素
BiTree Findmax(BiTree BST)
{
	if (BST)
	{
		while (BST->rchild)
		{
			BST = BST->rchild;
		}
	}
	return BST;
}

//为了记住查找失败时访问的最后一个结点，改进查找算法如下
int SearchBST(BiTree bt, int key, BiTree* p, BiTree* q)
{
	/*在根节点bt所指二叉树中递归地查找关键字等于key的结点，若查找成功指针q指向该节点并返回1；否则
	指针q指向查找路径上最后一个访问结点并返回0，指针p指向bt的双亲，初始调用时值为NULL*/
	if (!bt)  //查找失败
	{
		*q = *p;
		return 0;
	}

}

/*二叉排序树结点的删除*/
void Delete(BiTree& p)
{
	if (!p->rchild)  //只有左子树
	{

	}
	else if (!p->lchild)  //只有右子树
	{

	}
	else  //左右子树均有
	{

	}
}

int DeleteBST(BiTree* T, Datatype key)
{
	BiTree bst;
	bst = *T;
	//若二叉排序树T中存在其关键字等于key的数据元素，则删除该数据元素结点，并返回true，否则返回false
	if (!T)
	{
		return false;  //不存在关键字等于key的数据元素
	}
	else
	{
		if (key == bst->data)  //找到关键字等于key的数据元素
		{
			Delete(bst);
			return true;
		}
		else if (key < bst->data)
		{
			DeleteBST(&bst->lchild, key);  //继续在左子树中查找
		}
		else
		{
			DeleteBST(&bst->rchild, key);  //继续在右子树中查找
		}
	}
}
#endif // BINSORTREE
