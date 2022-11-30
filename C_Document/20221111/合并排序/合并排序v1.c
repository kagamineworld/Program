//�ϲ�����(Mergesort)
//����������
//��������:8,3,2,9,7,1,5,4
//�������:1,2,3,4,5,7,8,9

#include <stdio.h>

int a[100];
int input(int *a);                               //��������
void output(int *a, int n);                      //�������
void mergepass(int *a, int *b, int s, int n);    //�ϲ��ź������������
void mergesort(int *a, int n);                   //�ϲ�����
void merge(int *c, int *d, int l, int m, int r); //ʵ�־���ĺϲ��㷨

int main()
{
    int n;
    //��������
    n = input(a);
    printf("�����������Ϊ:\n");
    output(a, n);
    //���кϲ�����
    mergesort(a, n);
    //�������
    printf("����������Ϊ��\n");
    output(a, n);
    return 0;
}
int input(int *a) //��������Ԫ��
{
    int n, i;
    printf("��������������������а�����Ԫ�ظ���(ע:���һ�ٸ�):\n");
    scanf("%d", &n);
    printf("�����������\n");
    //��������
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    return n;
}
void output(int *a, int n) //�������Ϊn������
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void mergesort(int *a, int n) //�ϲ�����
{
    int b[100] = {0}; //��ʼ������
    int s = 1;        //��ʼ��s
    while (s < n)
    {
        mergepass(a, b, s, n);
        s += s;
        mergepass(b, a, s, n);
        s += s;
    }
}
void mergepass(int *a, int *b, int s, int n) //�ϲ��ź������������
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
void merge(int *a, int *b, int l, int m, int r) //ʵ�־���ĺϲ��㷨
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
