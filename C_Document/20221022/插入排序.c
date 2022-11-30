//插入排序
//伪代码：
//  ALGORITHM InsertionSort( A[0..n-1] )
//  输入：大小为n的无序序列A
//  输出：按非递减排列的序列A
//  for i ← 1 to n-1 do
// 	temp ← A[i]   // A[i] ：等待插入的元素
// 	j ← i-1           // A[0] - A[j] 已排序
// 	while j ≥ 0 and A[j] > temp do
// 	       A[j+1] ← A[j]
// 		   j ← j –1    // 从右往左移动有序元素，直到找到A[i] 插入位置
// 	A[j+1] ←temp // 当A[j] < temp时跳出循环，因此插入到A[j+1]

#include <stdio.h>
int a[100];
int input(int *a)
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

int main()
{
    int i, temp, j, n;
    n = input(a);
    printf("您输入的序列为：\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    //开始排序
    printf("\n开始排序！\n");
    for (i = 1; i < n; i++)
    {
        temp = a[i]; // A[i] ：等待插入的元素
        j = i - 1;   // A[0] - A[j] 已排序
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j = j - 1; // 从右往左移动有序元素，直到找到A[i] 插入位置
        }
        a[j + 1] = temp; // 当A[j] < temp时跳出循环，因此插入到A[j+1]
    }
    //输出排好后的该序列
    printf("排序后为:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}