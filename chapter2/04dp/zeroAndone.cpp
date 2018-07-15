//
// Created by Administrator on 2018/7/15 0015.
//  0,1背包问题
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 105
#define MAX_W 10000

using namespace std;
int n, W;

int v[MAX_N], w[MAX_N];



//暴力搜索

//从第i个物品开始挑选总重小于j的部分


int rec(int i, int j) {
    int res;
    if (i == n) {
        res = 0;
    } else if (j < w[i]) {
        res = rec(i + 1, j);
    } else {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }

    return res;
}


//记忆搜索

int mem[MAX_N][MAX_W];

int rec(int i, int j) {
    if (mem[i][j] > 0) {
        return dp[i][j];
    }
    int res;
    if (i == n) {
        res = 0;
    } else if (j < w[i]) {
        res = rec(i + 1, j);
    } else {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return dp[i][j] = res;
}


//  动态规划
int dp[MAX_N+1][MAX_W+1];

void slove(){
    for(int i=n-1;i>=0;i--) {
        for(j=0;j<=W;j++){
            if(j<w[i]){
                dp[i][j]=dp[i1][j];
            }else{
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[0][W];
}
