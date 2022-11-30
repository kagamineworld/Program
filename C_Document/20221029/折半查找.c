#include <stdio.h>
#define LEN 5
void binary_search(int *a, int temp, int len);

int main()
{
    int a[LEN] = {10, 20, 30, 40, 50};
    int input;
    int flag;

    flag = 1;

    while (flag == 1)
    {
        printf("请输入需要插入的数:\n");
        scanf("%d", &input);
        binary_search(*(a + 5), input, LEN);
        printf("请问是否要继续查找，如果需要继续查找请输入1，如果不需要请输入0：\n");
        scanf("%d", &flag);
    }

    return 0;
}

void binary_search(int *a, int input, int len)
{
    int i, j, n;
    int len_1;

    len_1 = len / 2;

    switch (len % 2)
    {
    case 0:
        if (input > a[len_1])
        {
            for (i = len_1; i < len; i++)
            {
                if (input >= a[len - 1])
                {
                    printf("0.0.这个数应该插入到最后一个数的后面！\n");
                    break;
                }
                else if (input <= a[0])
                {
                    printf("0.1.这个数应该插入到第一个数的前面！\n");
                    break;
                }
                else if (input > a[i])
                {
                    continue;
                }
                else
                {
                    printf("0.2.这个数应该插入%d到%d之间。\n", a[i - 1], a[i]);
                    break;
                }
            }
        }
        else
        {
            for (i = len_1; i >= 0; i--)
            {
                if (input >= a[len - 1])
                {
                    printf("1.0.这个数应该插入到最后一个数的后面！\n");
                    break;
                }
                else if (input <= a[0])
                {
                    printf("1.1.这个数应该插入到第一个数的前面！\n");
                    break;
                }
                else if (input < a[i])
                {
                    continue;
                }
                else
                {
                    printf("1.2.这个数应该插入%d到%d之间。\n", a[i], a[i + 1]);
                    break;
                }
            }
        }
        break;

    case 1:
        len_1 = len_1 + 1;
        if (input > a[len_1])
        {
            for (i = len_1; i < len; i++)
            {
                if (input > a[len - 1])
                {
                    printf("2.0.这个数应该插入到最后一个数的后面！\n");
                    break;
                }
                else if (input < a[0])
                {
                    printf("2.1.这个数应该插入到第一个数的前面！\n");
                    break;
                }
                else if (input > a[i])
                {
                    continue;
                }
                else
                {
                    printf("2.2.这个数应该插入%d到%d之间。\n", a[i - 1], a[i]);
                    break;
                }
            }
        }
        else
        {
            for (i = len_1; i >= 0; i--)
            {
                if (input > a[len - 1])
                {
                    printf("3.0.这个数应该插入到最后一个数的后面！\n");
                    break;
                }
                else if (input < a[0])
                {
                    printf("3.1.这个数应该插入到第一个数的前面！\n");
                    break;
                }
                else if (input < a[i])
                {
                    continue;
                }
                else
                {
                    printf("3.2.这个数应该插入%d到%d之间。\n", a[i], a[i + 1]);
                    break;
                }
            }
        }
        break;

    default:
        printf("error!\n");
        break;
    }
}