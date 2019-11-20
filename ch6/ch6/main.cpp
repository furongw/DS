#include <stdio.h>

#define MATRIXNUM 10
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




int main()
{
	int p[MATRIXNUM+1] = {9, 3,2,4,5,7,9,2,3,4,10};  //��˾����������
	printf("the min mul num is: %d", MatrixChainOrder(p));
}