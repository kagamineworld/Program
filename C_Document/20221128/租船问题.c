//租船问题
//
//输入站点数,n,每个站点到其他站点的租金；
//输出最少租金min;

#include <stdio.h>

int m[50][50][1] = {0};	   //存放已经计算过的值
int temp[50][50][1] = {0}; //存放计算最小
int db[50][50] = {0};	   //存放每个站点到其他站点的租金

int min_money(int i, int j);

int main()
{
	int money, length;
	int i, j;
	int m, n;
	//输入站点数以及每个站点到其他站点的租金
	printf("请输入轮船中转站站数(注:最多50个):\n");
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			printf("请输入第%d站到第%d站的租金:\n", i + 1, j + 1);
			scanf("%d", &db[i][j]);
		}
	}
	//输出站点数以及每个站点到其他站点的租金
	printf("您输入的每个站点到其他站点的金额为：\n");
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
			printf("第%d站到第%d站的租金为:%d\n", i + 1, j + 1, db[i][j]);
	}
	//输入需要找的两个站点序号
	printf("请输入你想计算的两个站点序号:\n");
	printf("第一个序号：");
	scanf("%d", &m);
	printf("第二个序号：");
	scanf("%d", &n);
	// money = min_money(m, n);
	//输出最少租金数额
	printf("最少金额为：%d\n", money);
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
