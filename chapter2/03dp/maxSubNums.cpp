//
// Created by Administrator on 2018/7/16 0016.
//  最长上升子序列

//给定一些数，求解最长的上升子序列长度
#include <iostream>
#include <algorithm>

using namespace std;

#define Max_N 10005

int n;
int a[Max_N];

int dp[Max_N];

void slove()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << res << endl;
}
