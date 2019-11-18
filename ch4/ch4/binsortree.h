#ifndef BINSORTREE
#define BINSORTREE


#include "tree.h"

//�����������洢�ṹ
typedef struct BSTNode
{
	int key;  //�ؼ�����
	struct BSTNode* lchild, * rchild;//���Һ���ָ��
}BSTNode, * BSTree;

//��������/�������Ĳ����㷨
BiTree Insert(Datatype x, BiTree &bst)
{
	if (!bst)  //��ԭ��Ϊ�գ����ɲ�����һ�����Ķ���������
	{
		bst = (BiTree)malloc(sizeof(BiTreeNode));
		bst->data = x;
		bst->lchild = NULL;
		bst->rchild = NULL;
	}
	else
	{
		if (x < bst->data)
		{
			bst->lchild = Insert(x, bst->lchild);  //�ݹ����������
		}
		else if(x>bst->data)
		{
			bst->rchild = Insert(x, bst->rchild);  //�ݹ����������
		}
		//else x�Ѵ��ڣ�ʲô������
	}
	return bst;
}

//����������������
BiTree Find(Datatype x, BiTree BST)
{
	if (!BST)
	{
		return NULL;//����ʧ��
	}
	if (x > BST->data)
	{
		return Find(x, BST->rchild);  //���������м�������
	}
	else if (x < BST->data)
	{
		return Find(x, BST->lchild);  //���������м�������
	}
	else //x==BST.data
	{
		return BST;  //���ҳɹ��������ҵ����ĵ�ַ
	}
}

//�����������ķǵݹ�Ѱ�ҷ�
BiTree IterFind(Datatype x, BiTree BST)
{
	while (BST)
	{
		if (x > BST->data)
		{
			BST = BST->rchild;  //�����������ƶ�����������
		}
		else if (x < BST->data)
		{
			BST = BST->lchild;  //�����������ƶ�����������
		}
		else  //x==BST.data
		{
			return BST;  //���ҳɹ������ؽ����ҵ����ĵ�ַ
		}
	}
	return NULL;
}

//�������Ԫ��
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

//Ϊ�˼�ס����ʧ��ʱ���ʵ����һ����㣬�Ľ������㷨����
int SearchBST(BiTree bt, int key, BiTree* p, BiTree* q)
{
	/*�ڸ��ڵ�bt��ָ�������еݹ�ز��ҹؼ��ֵ���key�Ľ�㣬�����ҳɹ�ָ��qָ��ýڵ㲢����1������
	ָ��qָ�����·�������һ�����ʽ�㲢����0��ָ��pָ��bt��˫�ף���ʼ����ʱֵΪNULL*/
	if (!bt)  //����ʧ��
	{
		*q = *p;
		return 0;
	}
	else if (key == bt->data)  //���ҳɹ�
	{
		*q = bt;
		return 1;
	}
	else if (key < bt->data)  //����������������
	{
		*p = bt;
		return SearchBST(bt->lchild, key, p, q);
	}
	else
	{
		*p = bt;
		return SearchBST(bt->rchild, key, p, q);
	}
}

/*��������������ɾ��*/
int DeleteBiTreeNode(BiTree* t, int key)
{
	BiTree p, f, s, q;
	if (SearchBST(*t, key, &f, &p) == 0)  //����ʧ��
	{
		return 0;
	}

	if (!(p->rchild))  //Ҷ����ֻ��������
	{
		if (f->lchild && f->lchild == p)
		{
			f->lchild = p->lchild;
		}
		else
		{
			f->rchild = p->lchild;
		}
	}
	else if(!(p->lchild))  //ֻ��������
	{
		if (f->lchild && f->lchild == p)
		{
			f->lchild = p->rchild;
		}
		else
		{
			f->rchild = p->rchild;
		}
	}
	else  //������������
	{
		q = p;
		s = p->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
	}
	return 1;
}


#endif // BINSORTREE
