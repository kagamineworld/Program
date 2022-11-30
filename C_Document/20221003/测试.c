#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//升序
int cmp1(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; 
}

//最优情况
int getMin(int *a, int n)
{
    int min = 0;                    //初始化min的值
    for (int i = 0; i < n - 1; i++) //循环n次
    {
        qsort(a + i, n - i, sizeof(int), &cmp1); //升序排序
        // printf("%d+%d=%d\n", a[i + 1],a[i],(a[i+1]+a[i]));
        a[i + 1] += a[i];  //更改数据
        // printf("min:%d+%d-1=%d\n",min,a[i+1],(min+a[i+1]-1));
        min += a[i + 1] - 1;
    }
    printf("最优情况min=%d\n", min);
    return min;
}

int main()
{
    int a[100], b[100];
    int n;

    //读取数据
    FILE *f1 = fopen("E:/这是E盘的桌面/program/C_Document/202210031137/input.txt", "r");
    if (f1 == NULL)
    {
        printf("文件打开失败");
        return 0;
    }
    fscanf(f1, "%d", &n);
    printf("要合并的序列为：");
    for (int i = 0; i < n; i++)
    {
        fscanf(f1, "%d", &a[i]);
        printf("%3d", a[i]);
        b[i] = a[i];
    }
    printf("\n");
    fclose(f1);

    //输出数据
    int min = getMin(a, n);
    FILE *f2 = fopen("E:/这是E盘的桌面/program/C_Document/202210031137/output.txt", "w");
    fprintf(f2, "%3d", min);
    fclose(f2);
    return 0;
}
