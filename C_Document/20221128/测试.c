#include <stdio.h>
int m[250];     //����Ѿ��������ֵ
int db[50][50]; //���ÿ��վ�㵽����վ������

int input(int **a);
void output(int **a);
// int input();
// void output();

int main()
{
    int money, n;
    //����վ�����Լ�ÿ��վ�㵽����վ������
    // n = input();
    n = input(db);
    printf("---------------\n");
    printf("%d\n", db[0][1]);
    printf("%d\n", db[0][2]);
    printf("%d\n", *(*(db + 1) + 2));
    //�������
    // output();
    output(db);
    // printf("���ٽ��Ϊ��%d", money);
    return 0;
}
int input(int **a) //��������Ԫ��
{
    int n, i, j;
    printf("�������ִ���תվվ��(ע:���50��):\n");
    scanf("%d", &n);
    //��������
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("�������%dվ����%dվ�����:\n", i, j);
            scanf("%d", (*(a + i) + j));
        }
    }
    return n;
}

void output(int **a) //�������Ԫ��
{
    int n, i, j;
    printf("��ǰ����Ϊ��\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("%d\t", *(*(a + i) + j));
        }
        printf("\n");
    }
}
// int input() //��������Ԫ��
// {
//     int n, i, j;
//     printf("�������ִ���תվվ��(ע:���50��):\n");
//     scanf("%d", &n);
//     //��������
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < i; j++)
//         {
//             printf("�������%dվ����%dվ�����:\n", i, j);
//             scanf("%d", &db[i][j]);
//         }
//     }
//     return n;
// }
// void output() //�������Ԫ��
// {
//     int n, i, j;
//     printf("��������Ϊ��\n");
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < i; j++)
//         {
//             printf("%d", db[i][j]);
//         }
//         printf("\n");
//     }
// }