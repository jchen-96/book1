// 有n种物品，每种物品有a(i)个。不同种类的物品可以互相区分，但是相同种类的物品
// 无法区分，从这些物品中取出m的话，有多少种取法，求出方案书模M的余数

#define Max_N 1000
#define Max_M 1000

#include <iostream>
#include <algorithm>

int a[Max_N];

//dp[i+1][j] 从前i中物品中取出j个的组合数
int dp[Max_N + 1][Max_M];

void slove()
{
    // 一个都不取的方法只有一种
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j - 1 - a[i] >= 0)
            {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] + dp[i][j - 1 - a[i]] + m) % m;
            }
            else
            {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % m;
            }
        }
    }

    cout << dp[n][m] << endl;
}