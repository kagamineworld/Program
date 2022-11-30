//�������˷�
//�㷨
// ��������nλ����a��b�Ļ���n������ż��
// ��a��ǰ�벿�ּ�Ϊa1����벿�ּ�Ϊa0
// ��b��ǰ�벿�ּ�Ϊb1����벿�ּ�Ϊb0
// a=a1*10^n/2+a0�� b=b1*10^n/2+b0
// c=a*b=(a1*10^n/2+a0)*(b1*10^n/2+b0)
//      =(a1*b1)*10^n+(a1*b0+a0*b1)*10^n/2+(a0*b0)
//      =c2*10^n+c1*10^n/2+c0
// c0= a0*b0
// c2= a1*b1
// c1= (a1+a0)*(b1+b0)-(c2+c1)
//����������
// number_1:1234
// number_2:9876
//�����12186984

#include <stdio.h>
#include <math.h>

int bignumber(int a, int b);
int judge(int a); //�ж�����λ��

int main()
{
    long a, b, c;
    printf("������������λ��������Ϊ��ż���Ĵ�����:\nnumber_1:");
    scanf("%ld", &a);
    printf("number_2:");
    scanf("%ld", &b);
    c = bignumber(a, b);
    printf("�������Ļ�Ϊ:%ld", c);
    return 0;
}
int judge(int a)
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        if (a >= (int)(pow(10, i)))
        {
            continue;
        }
        else
        {
            return i;
            break;
        }
    }
}
int bignumber(int a, int b)
{
    int a_0, a_1, a_2, n;
    int b_0, b_1, b_2;
    int c_0, c_1, c_2, c_n_0, c_n_1;
    long c; 
    

    n = judge(a);
    a_1 = a / (int)(pow(10, n / 2));
    a_0 = a - a_1 * (int)(pow(10, n / 2));
//    printf("a=%d,n=%d,a_0=%d,a_1=%d\n", a, n, a_0, a_1);

    b_1 = b / (int)(pow(10, n / 2));
    b_0 = b - b_1 * (int)(pow(10, n / 2));
//    printf("b=%d,b_0=%d,b_1=%d\n", b, b_0, b_1);

    c_0 = a_0 * b_0;
    c_2 = a_1 * b_1;
    c_1 = (a_1 * b_0) + (b_1 * a_0);
    c_n_0 = (int)(pow(10, n));
    c_n_1 = (int)(pow(10, n / 2));
    c = c_2 * c_n_0 + c_1 * c_n_1 + c_0;
//    printf("c=%d,c_0=%d,c_1=%d,c_2=%d,pow(10,n)=%d,pow(10,n/2)=%d\n", c,c_0, c_1, c_2,c_n_0,c_n_1);
    return c;
}
