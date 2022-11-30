#include <stdio.h>
#define MaxSize 100
#define MAX_INT 9999
#define Min(a, b) (a < b ? a : b)
int r[MaxSize + 1][MaxSize];

void solve(int n)
{
    int m[n + 1][n + 1];
    int minf;
    //��ʼ��m����
    for (int i = 1; i <= n; i++)
    {
        // m(i,1) = r(i,i+1);m(n,1) = 0;
        if (i == n)
            m[i][1] = 0;
        else
            m[i][1] = r[i][i + 1];

        for (int j = 2; j <= n; j++)
        {
            m[i][j] = MAX_INT;
            m[n][j] = 0;
        }
    }
    //�Զ����µݹ����
    for (int i = n - 1; i >= 1; i--)
    { //�ӵ�n-1վ��ʼ����  �������i=n��ʼ����m[n][j] = 0,���յ�վ��ʼ��û�������
        for (int j = 2; j <= n - i; j++)
        { // j��2��ʼ����Ϊ���j����1������m[i][1]=r[i][i+1],�Ѿ�����Сֵ��
            for (int s = 1; s < j; s++)
            { // s��ʾ��i~i+j�м��i+sվ�黹��ͧ������i+sվ��ʼ��һ�׶ε�����
                minf = Min(m[i][s] + m[i + s][j - s], r[i][i + j]);
                if (minf < m[i][j])
                    m[i][j] = minf;
            }
        }
    }
    printf("%d", m[1][n - 1]);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            scanf("%d", &r[i][j]);
    }
    solve(n);
    return 0;
}