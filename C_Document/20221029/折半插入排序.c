//折半插入排序
//伪代码：
//  binary_insert_sortv( a[0..n-1] )
//  输入：大小为n的无序序列a
//  输出：按非递减排列的序列a
//  int intsert;//设置为全局变量，用来记录插入位置
//  for i ← 1 to n-1 do
//     	temp ← a[i]        // a[i] ：等待插入的元素
//     	j ← i-1           // a[0] - a[j] 已排序
//     	binary_search(a, temp, j);//折半查找，输入数组a，查找的值temp，查找的范围j
//      for i_1 <- i to insert do //插入的位置是小于被判断元素的位置
//          a[i_1] = a[i_1 - 1];  //将需要替换位置以后的元素向后移到被判断元素的位置
//      a[insert] = temp;         //将需要插入的元素放入插入位置
//使用示例：
//输入：1 6 2 8 7
//输出：1 2 6 7 8

#include <stdio.h>
int a[100];
int insert;                                     //用来存放需要插入的元素位置
int input(int *a);                              //输入数组
void output(int *a, int n);                     //输出数组
void binary_insert_sort(int *a, int n);         //折半插入排序
void binary_search(int *a, int input, int len); //折半查找

int main()
{
    int i, n;
    n = input(a);
    printf("您输入的序列为：\n");
    output(a, n);
    //开始排序
    printf("\n开始排序！\n");
    binary_insert_sort(a, n); //折半插入排序
    //输出排好后的该序列
    printf("排序后为:\n");
    output(a, n);
    return 0;
}

int input(int *a) //用以输入数组元素
{
    int n, i;
    printf("请输入你想排序的序列中包含的元素个数(注:最多一百个):\n");
    scanf("%d", &n);
    printf("请输入该序列\n");
    //输入序列
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    return n;
}

void output(int *a, int n) //输出长度为n的数组
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void binary_insert_sort(int *a, int n) //折半插入排序
{
    int i, j, temp;
    int i_1;

    for (i = 1; i < n; i++)
    {
        temp = a[i]; // A[i] ：等待插入的元素
        j = i - 1;   // A[0] - A[j] 已排序

        binary_search(a, temp, j);
        // printf("现在是判断第%d的个，已经排序了%d个，现在需要插入的位置是%d\n", i, j, insert);
        for (i_1 = i; i_1 > insert; i_1--) //将需要替换位置的一直向后移直到等待插入的元素的位置
        {
            a[i_1] = a[i_1 - 1];
        }
        a[insert] = temp;
        // output(a, n);
        // printf("\n----------------\n");
        // while (j >= 0 && a[j] > temp)
        // {
        //     a[j + 1] = a[j];
        //     j = j - 1; // 从右往左移动有序元素，直到找到A[i] 插入位置
        // }
        // a[j + 1] = temp; // 当A[j] < temp时跳出循环，因此插入到A[j+1]
    }
}

void binary_search(int *a, int input, int len) //折半查找
{
    int i, j, n;
    int len_1;

    len_1 = len / 2;

    switch (len % 2)
    {
    case 0:                  //偶数的查找方向
        if (input >= a[len]) //判断输入值是否大于最大值或者小于最小值
        {
            // printf("0.0.这个数应该插入到最后一个数的后面！\n");
            insert = len + 1;
        }
        else if (input <= a[0])
        {
            // printf("0.1.这个数应该插入到第一个数的前面！\n");
            insert = 0;
        }
        else if (input > a[len_1]) //如果输入的值大于中间数往右边对比
        {
            for (i = len_1; i < len; i++)
            {
                if (input > a[i])
                {
                    continue;
                }
                else
                {
                    // printf("1.这个数应该插入到%d。\n", i - 1);
                    insert = i - 1;
                }
            }
        }
        else //如果输入的值小于中间数往左边对比
        {
            for (i = len_1; i >= 0; i--)
            {
                if (input < a[i])
                {
                    continue;
                }
                else
                {
                    // printf("2.这个数应该插入到%d。\n", i + 1);
                    insert = i + 1;
                }
            }
        }
        break;

    case 1: //奇数的查找方向
        len_1 = len_1 + 1;
        if (input >= a[len]) //判断输入值是否大于最大值或者小于最小值
        {
            // printf("3.0.这个数应该插入到最后一个数的后面！\n");
            insert = len + 1;
        }
        else if (input <= a[0])
        {
            // printf("3.1.这个数应该插入到第一个数的前面！\n");
            insert = 0;
        }
        else if (input > a[len_1]) //如果输入的值大于中间数往右边对比
        {
            for (i = len_1; i < len; i++)
            {
                if (input > a[i])
                {
                    continue;
                }
                else
                {
                    // printf("4.这个数应该插入到%d。\n", i - 1);
                    insert = i - 1;
                }
            }
        }
        else //如果输入的值小于中间数往左边对比
        {
            for (i = len_1; i >= 0; i--)
            {
                if (input < a[i])
                {
                    continue;
                }
                else
                {
                    // printf("5.这个数应该插入到%d。\n", i + 1);
                    insert = i + 1;
                }
            }
        }
        break;

    default:
        printf("error!\n");
        break;
    }
}