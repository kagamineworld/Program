//俄式乘法
//第一个因数除2，第二个因数乘2；
//若第一个因数除2余1，折第二因数乘2后加上乘2前的因数；
//伪代码：
//输入：两个整数a,b
//输出：这两个数的积
// while a/2!=1 do //循环除到1
//     if a % 2 == 1 do
//         rem <- rem+b//余数循环相加
//     a <- a/2//第一个因数除2
//     b <- b*2//第二个因数乘2
// pro <- rem+b//第二个因数加上余数循环的和

#include <stdio.h>
int main()
{
    int a, b, rem, pro;
    rem = 0;
    pro = 0;
    printf("本程序使用的是俄式乘法\n");
    printf("请输入第一个因数:\n");
    scanf("%d", &a);
    printf("请输入第二个因数:\n");
    scanf("%d", &b);
    while (a / 2 != 0) //循环除到1
    {
        if (a % 2 == 1)
            rem = rem + b; //余数循环相加
        // printf("rem=%d\n", rem);
        a = a / 2; //第一个因数除2
        // printf("a=%d\n", a);
        b = b * 2; //第二个因数乘2
        // printf("b=%d\n", b);
        // printf("----------------------\n");
    }
    pro = rem + b; //第二个因数加上余数循环的和
    printf("您输入的两个因数的和为:%d", pro);
}