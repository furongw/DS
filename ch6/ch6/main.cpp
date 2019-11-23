#include <stdio.h>

#define MATRIXNUM 3
#define NUMAX 10000

/*动态规划示例*/
//求矩阵连乘问题，求最小的计算量
int MatrixChainOrder(int p[])
{
	int m[MATRIXNUM+1][MATRIXNUM+1], s[MATRIXNUM+1][MATRIXNUM+1];  //m[n][n]存放m[i][j]的值，s[n][n]存放取m[i][j]时的k的值
	//这里从1开始存储
	int i, j, k, L, q;
	for (i = 1; i <= MATRIXNUM; i++)
	{
 		m[i][i] = 0;
	}
	for (L = 2; L <= MATRIXNUM; L++)  //L为链长变量
	{
		for (i = 1; i <= MATRIXNUM - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = NUMAX;
			for (k = i; k <= j - 1; k++)  //将链ij划分为A[i:k]*A[k+1:j]
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

/*备忘录算法*/
int lookupchain(int i,int j,int m[MATRIXNUM + 1][MATRIXNUM + 1], int s[MATRIXNUM + 1][MATRIXNUM + 1], int *p)
{
	int k,t;
	if(m[i][j]>0)  //已计算过
	{
		return m[i][j];
	}
	if (i == j) return 0;
	//初始化分解乘法
	int u = lookupchain(i+1 , j, m, s, p) + p[i-1 ] * p[i] * p[j];
	s[i][j] = i;  
    //选择分解问题最佳的k
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



//与动态规划不同，备忘录算法是自顶向下
int memorizedmatrixchain(int n, int m[MATRIXNUM+1][MATRIXNUM+1],int s[MATRIXNUM + 1][MATRIXNUM + 1],int *p)
{
	//m[n][n]存放m[i][j]的值，s[n][n]存放取m[i][j]时的k的值，m和j从1开始存储
	//m存放
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
	int p[MATRIXNUM+1] = {9, 3,2,4};  //相乘矩阵的行列数
	printf("the min mul num is: %d", MatrixChainOrder(p));
	int m[MATRIXNUM + 1][MATRIXNUM + 1] = {0}, s[MATRIXNUM + 1][MATRIXNUM + 1];
	
	printf("\n");
	printf("the min mul num is: %d", memorizedmatrixchain(MATRIXNUM,m,s,p));
}