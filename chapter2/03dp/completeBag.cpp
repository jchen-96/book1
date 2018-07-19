//
// Created by Administrator on 2018/7/15 0015.
//  完全背包问题
// 和0 1背包问题不同的是，这里的每件物品没有数量限制
// 在递推的过程中尝试每一种物品的每一种可能的件数


#include <iostream>
#include <algorithm>

#define MAX_N 100
#define MAX_W 10000

using namespace std;

int w[MAX_N];
int v[MAX_N];

int dp[MAX_N + 1][MAX_W];
int n, w;


//基本做法
void slove() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            for (int k = 0; k * w[i] <= j; k++) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
            }
        }
    }

    cout << dp[n][W];
}

//优化做法

void slove() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j < w[i]){
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max{dp[i][j], dp[i + 1][j - w[i]] + v[i]};
            }
        }
    }
    cout<<dp[n][w]<<endl;
}




