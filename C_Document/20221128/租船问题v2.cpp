#include <stdio.h>
#define MaxSize 100
#define MAX_INT 9999
#define Min(a, b) (a < b ? a : b)
int r[MaxSize + 1][MaxSize];

void solve(int n)
{
    int m[n + 1][n + 1];
    int minf;
    //初始化m数组
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
    //自顶向下递归计算
    for (int i = n - 1; i >= 1; i--)
    { //从第n-1站开始计算  ，如果从i=n开始，则m[n][j] = 0,从终点站开始是没有意义的
        for (int j = 2; j <= n - i; j++)
        { // j从2开始，因为如果j等于1，就是m[i][1]=r[i][i+1],已经是最小值了
            for (int s = 1; s < j; s++)
            { // s表示在i~i+j中间的i+s站归还游艇，并从i+s站开始下一阶段的旅行
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