#include <stdio.h>
#define MaxSize 100
#define MAX_INT 9999
#define Min(a, b) (a < b ? a : b)

int db[50][50] = {0}; //存放每个站点到其他站点的租金

int min_money(int n);

int main()
{
    int money, length;
    int i, j;
    int m, n;
    //输入站点数以及每个站点到其他站点的租金
    printf("请输入轮船中转站站数(注:最多50个):\n");
    scanf("%d", &length);
    for (i = 0; i < length-1; i++)
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
    money = min_money(length);
    //输出最少租金数额
    printf("最少金额为：%d\n", money);
    return 0;
}
int min_money(int n)
{
   int i,j;
   int min[n];
   int money;
   min[n-2]=db[i][n-1];
   for(i=n-3;i>=0;i--)
   {
   	money=db[i][n-1];
   	for(j=i+1;j<n-1;j++)
   	{
   		money=Min(db[i][j]+min[j,money];
	   }
	   min[i]=money;
	} 
	return 0;
}
