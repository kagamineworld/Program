#include <stdio.h>

int main()
{
    int s[7] = {1, 2, 2, 2, 3, 3, 5};
    int z[20][2] = {0};
    int i, j, a, b, flag,max;
    flag = 0;
    max = 0;

    for (i = 0; i < 7; i++) //循环遍历整个数组
    {
        a = s[i]; //将第i个元素赋值给a
        b = 0;    //每次循环都要初始化b的值
        if (i > 0 && s[i] == s[i - 1]) //当是s[i]等于s[i-1]的时候就跳过本次循环，这里是为了找到可能成为众数的数
            continue;
        else //否则开始计算第i的个数的重数
        {
            for (j = i; j < (7); j++) //因为第i的个数的前面的数都已经比较过了，所以只需要比较第i的个数之后的数
            {
                if (a == s[j]) //判断与当前的数是否相等
                    b++;       //如果相等，自加
                else
                    continue; //否则跳过本次循环
            }
        }
        if (b <= 1) //计数b大于1的说明可能是众数
            continue;
        else //如果将得到的众数和它的重数放入二维数组z中，使用flag记录录入的众数
        {
            for (flag; flag < 20;) //用于保存众数和相应的重数
            {
                // printf("%d\n",flag);
                z[flag][0] = a;
                z[flag][1] = b;
                flag++;
                break;
            }
        }
    }
    for ( i=0; i < 20; i++)//用于找出最大的众数
    {
        if(flag>1 && flag!=0)
        {
            if (z[max][1]<z[flag][1])
                max = flag;
            else if(z[max][1]==z[flag][1]){
                if (z[max][0]<z[flag][0])
                    max=flag;
                else
                    continue;
            }
            else
                continue;
        }
        else if(flag == 0)
            printf("该集合没有众数。");
        else
            printf("这个数组的众数是%d，它的重数为%d",z[0][0],z[0][1]);
    }
    printf("该数组的众数是%d，它的重数为%d",z[max][0],z[max][1]);
    return 0;
}
