//�۰��������
//α���룺
//  binary_insert_sortv( a[0..n-1] )
//  ���룺��СΪn����������a
//  ��������ǵݼ����е�����a
//  int intsert;//����Ϊȫ�ֱ�����������¼����λ��
//  for i �� 1 to n-1 do
//     	temp �� a[i]        // a[i] ���ȴ������Ԫ��
//     	j �� i-1           // a[0] - a[j] ������
//     	binary_search(a, temp, j);//�۰���ң���������a�����ҵ�ֵtemp�����ҵķ�Χj
//      for i_1 <- i to insert do //�����λ����С�ڱ��ж�Ԫ�ص�λ��
//          a[i_1] = a[i_1 - 1];  //����Ҫ�滻λ���Ժ��Ԫ������Ƶ����ж�Ԫ�ص�λ��
//      a[insert] = temp;         //����Ҫ�����Ԫ�ط������λ��
//ʹ��ʾ����
//���룺1 6 2 8 7
//�����1 2 6 7 8

#include <stdio.h>
int a[100];
int insert;                                     //���������Ҫ�����Ԫ��λ��
int input(int *a);                              //��������
void output(int *a, int n);                     //�������
void binary_insert_sort(int *a, int n);         //�۰��������
void binary_search(int *a, int input, int len); //�۰����

int main()
{
    int i, n;
    n = input(a);
    printf("�����������Ϊ��\n");
    output(a, n);
    //��ʼ����
    printf("\n��ʼ����\n");
    binary_insert_sort(a, n); //�۰��������
    //����źú�ĸ�����
    printf("�����Ϊ:\n");
    output(a, n);
    return 0;
}

int input(int *a) //������������Ԫ��
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

void output(int *a, int n) //�������Ϊn������
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void binary_insert_sort(int *a, int n) //�۰��������
{
    int i, j, temp;
    int i_1;

    for (i = 1; i < n; i++)
    {
        temp = a[i]; // A[i] ���ȴ������Ԫ��
        j = i - 1;   // A[0] - A[j] ������

        binary_search(a, temp, j);
        // printf("�������жϵ�%d�ĸ����Ѿ�������%d����������Ҫ�����λ����%d\n", i, j, insert);
        for (i_1 = i; i_1 > insert; i_1--) //����Ҫ�滻λ�õ�һֱ�����ֱ���ȴ������Ԫ�ص�λ��
        {
            a[i_1] = a[i_1 - 1];
        }
        a[insert] = temp;
        // output(a, n);
        // printf("\n----------------\n");
        // while (j >= 0 && a[j] > temp)
        // {
        //     a[j + 1] = a[j];
        //     j = j - 1; // ���������ƶ�����Ԫ�أ�ֱ���ҵ�A[i] ����λ��
        // }
        // a[j + 1] = temp; // ��A[j] < tempʱ����ѭ������˲��뵽A[j+1]
    }
}

void binary_search(int *a, int input, int len) //�۰����
{
    int i, j, n;
    int len_1;

    len_1 = len / 2;

    switch (len % 2)
    {
    case 0:                  //ż���Ĳ��ҷ���
        if (input >= a[len]) //�ж�����ֵ�Ƿ�������ֵ����С����Сֵ
        {
            // printf("0.0.�����Ӧ�ò��뵽���һ�����ĺ��棡\n");
            insert = len + 1;
        }
        else if (input <= a[0])
        {
            // printf("0.1.�����Ӧ�ò��뵽��һ������ǰ�棡\n");
            insert = 0;
        }
        else if (input > a[len_1]) //��������ֵ�����м������ұ߶Ա�
        {
            for (i = len_1; i < len; i++)
            {
                if (input > a[i])
                {
                    continue;
                }
                else
                {
                    // printf("1.�����Ӧ�ò��뵽%d��\n", i - 1);
                    insert = i - 1;
                }
            }
        }
        else //��������ֵС���м�������߶Ա�
        {
            for (i = len_1; i >= 0; i--)
            {
                if (input < a[i])
                {
                    continue;
                }
                else
                {
                    // printf("2.�����Ӧ�ò��뵽%d��\n", i + 1);
                    insert = i + 1;
                }
            }
        }
        break;

    case 1: //�����Ĳ��ҷ���
        len_1 = len_1 + 1;
        if (input >= a[len]) //�ж�����ֵ�Ƿ�������ֵ����С����Сֵ
        {
            // printf("3.0.�����Ӧ�ò��뵽���һ�����ĺ��棡\n");
            insert = len + 1;
        }
        else if (input <= a[0])
        {
            // printf("3.1.�����Ӧ�ò��뵽��һ������ǰ�棡\n");
            insert = 0;
        }
        else if (input > a[len_1]) //��������ֵ�����м������ұ߶Ա�
        {
            for (i = len_1; i < len; i++)
            {
                if (input > a[i])
                {
                    continue;
                }
                else
                {
                    // printf("4.�����Ӧ�ò��뵽%d��\n", i - 1);
                    insert = i - 1;
                }
            }
        }
        else //��������ֵС���м�������߶Ա�
        {
            for (i = len_1; i >= 0; i--)
            {
                if (input < a[i])
                {
                    continue;
                }
                else
                {
                    // printf("5.�����Ӧ�ò��뵽%d��\n", i + 1);
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