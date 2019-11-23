#include <stdio.h>

#define MATRIXNUM 3
#define NUMAX 10000

/*��̬�滮ʾ��*/
//������������⣬����С�ļ�����
int MatrixChainOrder(int p[])
{
	int m[MATRIXNUM+1][MATRIXNUM+1], s[MATRIXNUM+1][MATRIXNUM+1];  //m[n][n]���m[i][j]��ֵ��s[n][n]���ȡm[i][j]ʱ��k��ֵ
	//�����1��ʼ�洢
	int i, j, k, L, q;
	for (i = 1; i <= MATRIXNUM; i++)
	{
 		m[i][i] = 0;
	}
	for (L = 2; L <= MATRIXNUM; L++)  //LΪ��������
	{
		for (i = 1; i <= MATRIXNUM - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = NUMAX;
			for (k = i; k <= j - 1; k++)  //����ij����ΪA[i:k]*A[k+1:j]
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}

	}
	return m[1][MATRIXNUM];
}

/*����¼�㷨*/
int lookupchain(int i,int j,int m[MATRIXNUM + 1][MATRIXNUM + 1], int s[MATRIXNUM + 1][MATRIXNUM + 1], int *p)
{
	int k,t;
	if(m[i][j]>0)  //�Ѽ����
	{
		return m[i][j];
	}
	if (i == j) return 0;
	//��ʼ���ֽ�˷�
	int u = lookupchain(i+1 , j, m, s, p) + p[i-1 ] * p[i] * p[j];
	s[i][j] = i;  
    //ѡ��ֽ�������ѵ�k
	for (k = i + 1; k < j; k++)
	{
		t = lookupchain(i, k, m, s, p) + lookupchain(k + 1, j,m,s,p) + p[i-1] * p[k] * p[j];
		if (t < u)
		{
			u = t;
			s[i][j] = k;
		}
		m[i][j] = u;
		
	}
	return u;
}



//�붯̬�滮��ͬ������¼�㷨���Զ�����
int memorizedmatrixchain(int n, int m[MATRIXNUM+1][MATRIXNUM+1],int s[MATRIXNUM + 1][MATRIXNUM + 1],int *p)
{
	//m[n][n]���m[i][j]��ֵ��s[n][n]���ȡm[i][j]ʱ��k��ֵ��m��j��1��ʼ�洢
	//m���
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			m[i][j] = 0;
		}
	}
	return lookupchain(1, n , m, s, p);
}




int main()
{
	int i;
	int p[MATRIXNUM+1] = {9, 3,2,4};  //��˾����������
	printf("the min mul num is: %d", MatrixChainOrder(p));
	int m[MATRIXNUM + 1][MATRIXNUM + 1] = {0}, s[MATRIXNUM + 1][MATRIXNUM + 1];
	
	printf("\n");
	printf("the min mul num is: %d", memorizedmatrixchain(MATRIXNUM,m,s,p));
}