#include <stdio.h>
#define NUM 500

int money[4][2] = {{1, 0}, {2, 0}, {5, 0}, {10, 0}};
int lib[NUM] = {0};

int find_m(int n);

int main()
{
    int n, m;
    printf("��������Ҫ��������\n");
    scanf("%d", &n);
    m = find_m(n);
    printf("������Ҫ��%d��Ӳ��\n", m);
    printf("һ�����Ҫ%d��,�������Ҫ%d��,������Ҫ%d��,ʮ�����Ҫ%d��\n", money[0][1], money[1][1], money[2][1], money[3][1]);
    return 0;
}

int find_m(int n)
{
    int i, temp;
    int money_n = 0;
    if (lib[n] != 0)
    {
        return lib[n];
    }
    else if (n >= money[3][0])
    {
        money[3][1] = n / money[3][0];
        temp = n % money[3][0];
        money_n = find_m(temp) + money[3][1];
        if (temp == 0)
        {
            lib[n] = money_n;
            return lib[n];
        }
    }
    else if (n >= money[2][0])
    {
        money[2][1] = n / money[2][0];
        temp = n % money[2][0];
        money_n = find_m(temp) + money[2][1];
    }
    else if (n >= money[1][0])
    {
        money[1][1] = n / money[1][0];
        temp = n % money[1][0];
        money_n = find_m(temp) + money[1][1];
        if (temp == 0)
        {
            lib[n] = money_n;
            return lib[n];
        }
    }
    else if (n >= money[0][0])
    {
        money[0][1] = n / money[0][0];
        temp = n % money[0][0];
        money_n = find_m(temp) + money[0][1];
        if (temp == 0)
        {
            lib[n] = money_n;
            return lib[n];
        }
    }
    else if (n == 0)
    {
        return lib[n];
    }
}