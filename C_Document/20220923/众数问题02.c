#include <stdio.h>

int main()
{
    int s[7] = {1, 2, 2, 2, 3, 3, 5};
    int z[20][2] = {0};
    int i, j, a, b, flag,max;
    flag = 0;
    max = 0;

    for (i = 0; i < 7; i++) //ѭ��������������
    {
        a = s[i]; //����i��Ԫ�ظ�ֵ��a
        b = 0;    //ÿ��ѭ����Ҫ��ʼ��b��ֵ
        if (i > 0 && s[i] == s[i - 1]) //����s[i]����s[i-1]��ʱ�����������ѭ����������Ϊ���ҵ����ܳ�Ϊ��������
            continue;
        else //����ʼ�����i�ĸ���������
        {
            for (j = i; j < (7); j++) //��Ϊ��i�ĸ�����ǰ��������Ѿ��ȽϹ��ˣ�����ֻ��Ҫ�Ƚϵ�i�ĸ���֮�����
            {
                if (a == s[j]) //�ж��뵱ǰ�����Ƿ����
                    b++;       //�����ȣ��Լ�
                else
                    continue; //������������ѭ��
            }
        }
        if (b <= 1) //����b����1��˵������������
            continue;
        else //������õ����������������������ά����z�У�ʹ��flag��¼¼�������
        {
            for (flag; flag < 20;) //���ڱ�����������Ӧ������
            {
                // printf("%d\n",flag);
                z[flag][0] = a;
                z[flag][1] = b;
                flag++;
                break;
            }
        }
    }
    for ( i=0; i < 20; i++)//�����ҳ���������
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
            printf("�ü���û��������");
        else
            printf("��������������%d����������Ϊ%d",z[0][0],z[0][1]);
    }
    printf("�������������%d����������Ϊ%d",z[max][0],z[max][1]);
    return 0;
}
