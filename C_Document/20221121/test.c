
#include <stdio.h>
#define NUM 50

int money[4][2] = {{1, 0}, {2, 0}, {5, 0}, {10, 0}};
int lib[NUM] = {0};

int find_m(int n);

int main()
{
    int n, m;
    // printf("请输入需要找零的数额：\n");
    // scanf("%d", &n);
    // m = find_m(n);
    // printf("最少需要找%d块硬币", m);
    printf("%d", money[0][0]);
    return 0;
}
int find_m(int n)
{
    int i, temp;
    int money_n = 0;
    for (i = 1; i < NUM; i++)
    {
        if (lib[n] == lib[i])
        {
            return lib[i];
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
            if (temp == 0)
            {
                lib[n] = money_n;
                return lib[n];
            }
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
    }
}