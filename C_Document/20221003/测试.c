#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//����
int cmp1(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; 
}

//�������
int getMin(int *a, int n)
{
    int min = 0;                    //��ʼ��min��ֵ
    for (int i = 0; i < n - 1; i++) //ѭ��n��
    {
        qsort(a + i, n - i, sizeof(int), &cmp1); //��������
        // printf("%d+%d=%d\n", a[i + 1],a[i],(a[i+1]+a[i]));
        a[i + 1] += a[i];  //��������
        // printf("min:%d+%d-1=%d\n",min,a[i+1],(min+a[i+1]-1));
        min += a[i + 1] - 1;
    }
    printf("�������min=%d\n", min);
    return min;
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
    FILE *f2 = fopen("E:/����E�̵�����/program/C_Document/202210031137/output.txt", "w");
    fprintf(f2, "%3d", min);
    fclose(f2);
    return 0;
}
