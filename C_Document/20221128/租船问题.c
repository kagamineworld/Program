//�⴬����
//
//����վ����,n,ÿ��վ�㵽����վ������
//����������min;

#include <stdio.h>

int m[50][50][1] = {0};	   //����Ѿ��������ֵ
int temp[50][50][1] = {0}; //��ż�����С
int db[50][50] = {0};	   //���ÿ��վ�㵽����վ������

int min_money(int i, int j);

int main()
{
	int money, length;
	int i, j;
	int m, n;
	//����վ�����Լ�ÿ��վ�㵽����վ������
	printf("�������ִ���תվվ��(ע:���50��):\n");
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			printf("�������%dվ����%dվ�����:\n", i + 1, j + 1);
			scanf("%d", &db[i][j]);
		}
	}
	//���վ�����Լ�ÿ��վ�㵽����վ������
	printf("�������ÿ��վ�㵽����վ��Ľ��Ϊ��\n");
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
			printf("��%dվ����%dվ�����Ϊ:%d\n", i + 1, j + 1, db[i][j]);
	}
	//������Ҫ�ҵ�����վ�����
	printf("������������������վ�����:\n");
	printf("��һ����ţ�");
	scanf("%d", &m);
	printf("�ڶ�����ţ�");
	scanf("%d", &n);
	// money = min_money(m, n);
	//��������������
	printf("���ٽ��Ϊ��%d\n", money);
	return 0;
}
int min_money(int m, int n)
{
	int money;
	int k;
	money = 0;
	if (m < n)
	{
		if (db[m][n] == 0)
		{
			money = min_money(m, k) + min_money(k, n);
			db[m][n] = money;
		}
		else
			return money;
	}
	else if (m == n)
		return 0;
	else
		printf("error!!!");
	return money;
}
int money_count(int m, int n)
{
}
