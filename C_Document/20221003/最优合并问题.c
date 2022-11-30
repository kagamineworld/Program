#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//����
int cmp1(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; 
}

//����
int cmp2(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

//�������
int getMin(int *a, int n)
{
    int min = 0;                    //��ʼ��min��ֵ
    for (int i = 0; i < n - 1; i++) //ѭ��n��
    {
        qsort(a + i, n - i, sizeof(int), &cmp1); //�ɵ͵��ߣ���������
        // printf("%d+%d=%d\n", a[i + 1],a[i],(a[i+1]+a[i]));
        a[i + 1] += a[i];                        //��������
        // printf("min:%d+%d-1=%d\n",min,a[i+1],(min+a[i+1]-1));
        min += a[i + 1] - 1;
    }
    printf("�������min=%d\n", min);
    return min;
}

//������
int getMax(int *b, int n)
{
    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        qsort(b + i, n - 1, sizeof(int), &cmp2); //����
        // printf("%d+%d=%d\n", b[i + 1],b[i],(b[i+1]+b[i]));
        b[i + 1] += b[i];
        // printf("max:%d+%d-1=%d\n",max,b[i+1],(max+b[i+1]-1));
        max += b[i + 1] - 1;
    }
    printf("������max=%d\n", max);
    return max;
}

int main()
{
    int a[100], b[100];
    int n;

    //��ȡ����
    FILE *f1 = fopen("E:/����E�̵�����/program/C_Document/202210031137/input.txt", "r");
    if (f1 == NULL)
    {
        printf("�ļ���ʧ��");
        return 0;
    }
    fscanf(f1, "%d", &n);
    printf("Ҫ�ϲ�������Ϊ��");
    for (int i = 0; i < n; i++)
    {
        fscanf(f1, "%d", &a[i]);
        printf("%3d", a[i]);
        b[i] = a[i];
    }
    printf("\n");
    fclose(f1);

    //�������
    int min = getMin(a, n);
    int max = getMax(b, n);
    FILE *f2 = fopen("E:/����E�̵�����/program/C_Document/202210031137/output.txt", "w");
    fprintf(f2, "%3d,%3d", min, max);
    fclose(f2);
    return 0;
}
