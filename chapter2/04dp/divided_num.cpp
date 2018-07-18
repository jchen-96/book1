#include <iostream>
// 有n各无区别的物品，将他们划分成不超过m组，求出划分方法数模M的余数
#define Max_N 1000
#define Max_M 1000

using namespace std;

int n, m;

// dp[i][j] j的i划分总数
int dp[Max_M][Max_N];

void solve()
{
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j - 1 >= 0)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][n] << endl;
}
