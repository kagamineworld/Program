#include <stdio.h>
int m[250];     //存放已经计算过的值
int db[50][50]; //存放每个站点到其他站点的租金

int input(int **a);
void output(int **a);
// int input();
// void output();

int main()
{
    int money, n;
    //输入站点数以及每个站点到其他站点的租金
    // n = input();
    n = input(db);
    printf("---------------\n");
    printf("%d\n", db[0][1]);
    printf("%d\n", db[0][2]);
    printf("%d\n", *(*(db + 1) + 2));
    //输出数组
    // output();
    output(db);
    // printf("最少金额为：%d", money);
    return 0;
}
int input(int **a) //输入数组元素
{
    int n, i, j;
    printf("请输入轮船中转站站数(注:最多50个):\n");
    scanf("%d", &n);
    //输入序列
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("请输入第%d站到第%d站的租金:\n", i, j);
            scanf("%d", (*(a + i) + j));
        }
    }
    return n;
}

void output(int **a) //输出数组元素
{
    int n, i, j;
    printf("当前数组为：\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("%d\t", *(*(a + i) + j));
        }
        printf("\n");
    }
}
// int input() //输入数组元素
// {
//     int n, i, j;
//     printf("请输入轮船中转站站数(注:最多50个):\n");
//     scanf("%d", &n);
//     //输入序列
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < i; j++)
//         {
//             printf("请输入第%d站到第%d站的租金:\n", i, j);
//             scanf("%d", &db[i][j]);
//         }
//     }
//     return n;
// }
// void output() //输出数组元素
// {
//     int n, i, j;
//     printf("当年数组为：\n");
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < i; j++)
//         {
//             printf("%d", db[i][j]);
//         }
//         printf("\n");
//     }
// }