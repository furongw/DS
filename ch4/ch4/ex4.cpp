#include <stdio.h>
#include <stdlib.h>


//��ϰ4  ����㷨���������������ڵ��ֵ����Ӧ�Ĳ���������Զ�Ԫ�����ʽ����
typedef int Datatype;

//���Ĵ洢�ṹ
//��������
typedef struct BiTreeNode
{
	Datatype data;  //����
	struct BiTreeNode* lchild;  //����
	struct BiTreeNode* rchild;  //�Һ���
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



//ǰ�����
void PreOrder(BiTree bt, int layer)
{
	//layerָʾ��ǰ��������ʼֵΪ1
	if (bt != NULL)
	{
		visit(bt->data,layer);  ////���ʺ�������ʵ���������
		PreOrder(bt->lchild,layer+1);
		PreOrder(bt->rchild,layer);
	}
}

int main()
{
	BiTreeNode node;
	BiTree p = &node;
	int i;

	//��ʼ��һ����������
	initfullbintree(&p, 4, 1);

	printf("preorder:\n");
	PreOrder(p,0);
}