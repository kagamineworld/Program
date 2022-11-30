#include <stdio.h>
#define MaxSize 100
#define MAX_INT 9999
#define Min(a, b) (a < b ? a : b)

int db[50][50] = {0}; //���ÿ��վ�㵽����վ������

int min_money(int n);

int main()
{
    int money, length;
    int i, j;
    int m, n;
    //����վ�����Լ�ÿ��վ�㵽����վ������
    printf("�������ִ���תվվ��(ע:���50��):\n");
    scanf("%d", &length);
    for (i = 0; i < length-1; i++)
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
    money = min_money(length);
    //��������������
    printf("���ٽ��Ϊ��%d\n", money);
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
