//��������
//α���룺
//  ALGORITHM InsertionSort( A[0..n-1] )
//  ���룺��СΪn����������A
//  ��������ǵݼ����е�����A
//  for i �� 1 to n-1 do
// 	temp �� A[i]   // A[i] ���ȴ������Ԫ��
// 	j �� i-1           // A[0] - A[j] ������
// 	while j �� 0 and A[j] > temp do
// 	       A[j+1] �� A[j]
// 		   j �� j �C1    // ���������ƶ�����Ԫ�أ�ֱ���ҵ�A[i] ����λ��
// 	A[j+1] ��temp // ��A[j] < tempʱ����ѭ������˲��뵽A[j+1]

#include <stdio.h>
int a[100];
int input(int *a)
{
    int n, i;
    printf("��������������������а�����Ԫ�ظ���(ע:���һ�ٸ�):\n");
    scanf("%d", &n);
    printf("�����������\n");
    //��������
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
    printf("�����������Ϊ��\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    //��ʼ����
    printf("\n��ʼ����\n");
    for (i = 1; i < n; i++)
    {
        temp = a[i]; // A[i] ���ȴ������Ԫ��
        j = i - 1;   // A[0] - A[j] ������
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j = j - 1; // ���������ƶ�����Ԫ�أ�ֱ���ҵ�A[i] ����λ��
        }
        a[j + 1] = temp; // ��A[j] < tempʱ����ѭ������˲��뵽A[j+1]
    }
    //����źú�ĸ�����
    printf("�����Ϊ:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}