#ifndef GREEDY
# define GREEDY

//���������������Ž��̰���㷨
float greedy_knapsack(float p[], float w[], float m, float x[], float n)
{
	//p[n]��w[n]�ǰ��Լ۱Ƚ������е�n����Ʒ�ļ�ֵ��������m�Ǳ�����������С����x[n]
	int i;
	float cu = m;
	float sum = 0;  //cu�Ǳ���ʣ������
	for (i = 0; i < n; i++)
	{
		x[i] = 0;  //����������ʼ��Ϊ��
	}
	for (i = 0; i < n; i++)  //��װ
	{
		if (w[i] > cu)
		{
			break;
		}
		x[i] = 1;
		cu -= w[i];
		sum += p[i];
	}
	if (i < n && cu>0)  //ɢװ
	{
		x[i] = cu / w[i];
		sum += p[i] * cu / w[i];
	}
	return sum;
}

#endif // !GREEDY
