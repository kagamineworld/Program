//合并排序(Mergesort)
//试验样例：
//输入数组:8,3,2,9,7,1,5,4
//输出数组:1,2,3,4,5,7,8,9

#include <stdio.h>

int a[100];
int input(int *a);                               //输入数组
void output(int *a, int n);                      //输出数组
void mergepass(int *a, int *b, int s, int n);    //合并排好序的相邻数段
void mergesort(int *a, int n);                   //合并排序
void merge(int *c, int *d, int l, int m, int r); //实现具体的合并算法

int main()
{
    int n;
    //输入数组
    n = input(a);
    printf("你输入的数组为:\n");
    output(a, n);
    //进行合并排序
    mergesort(a, n);
    //输出数组
    printf("排序后的数组为：\n");
    output(a, n);
    return 0;
}
int input(int *a) //输入数组元素
{
    int n, i;
    printf("请输入你想排序的序列中包含的元素个数(注:最多一百个):\n");
    scanf("%d", &n);
    printf("请输入该序列\n");
    //输入序列
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    return n;
}
void output(int *a, int n) //输出长度为n的数组
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void mergesort(int *a, int n) //合并排序
{
    int b[100] = {0}; //初始化数组
    int s = 1;        //初始化s
    while (s < n)
    {
        mergepass(a, b, s, n);
        s += s;
        mergepass(b, a, s, n);
        s += s;
    }
}
void mergepass(int *a, int *b, int s, int n) //合并排好序的相邻数段
{
    int i = 0;
    while (i <= n - 2 * s)
    {
        merge(a, b, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }
    if (i + s < n)
        merge(a, b, i, i + s - 1, n - 1);
    else
        for (int j = i; j <= n - 1; j++)
            b[j] = a[j];
}
void merge(int *a, int *b, int l, int m, int r) //实现具体的合并算法
{
    int i = l, j = m + 1, k = l;
    int q;
    while ((i <= m) && (j <= r))
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
        if (i > m)
        {
            for (q = j; q <= r; q++)
                b[k++] = a[q];
        }
        else
        {
            for (q = i; q <= m; q++)
                b[k++] = a[q];
        }
    }
}
