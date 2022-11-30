#include <stdio.h>
int main()
{
    int a, b, c, d, i, j;
    int sum, quo;
    for (i = 1; i < 10; i++)
    {
        d = i;
        sum = d * 100000 + d * 10000 + d * 1000 + d * 100 + d * 10 + d;
        for (j = 3; j < 10; j++)
        {
            a = j;
            quo = sum / a;
            if (quo / 10000 > 0 && quo / 10000 < 10 && (quo / 10000) == a && quo / 10000==a&&((quo % 10000) / 1000)==(quo % 10)&&a==(quo % 100) / 10)
            {
                printf("A=%d,B=%d,C=%d,A=%d,B=%d\n", quo / 10000, (quo % 10000) / 1000, (quo % 1000) / 100, (quo % 100) / 10, quo % 10);
            }
            // else if (quo / 10000 > 0 && quo / 10000 < 10 && (quo / 10000) == a)
            // {
            //     printf("a=%d\n", a);
            //     printf("d=%d\n", d);
            //     printf("DDDDDD?%d\n", sum);
            //     printf("ABCAB%d\n", quo);
            //     printf("A=%d,B=%d,C=%d,A=%d,B=%d\n", quo / 10000, (quo % 10000) / 1000, (quo % 1000) / 100, (quo % 100) / 10, quo % 10);
            //     printf("error!\n");
            //     printf("---------------------------\n");
            // }
        }
    }
    return 0;
}