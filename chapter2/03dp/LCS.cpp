//
// Created by Administrator on 2018/7/15 0015.
//  最长公共子序列
//全局变量会自动置零


#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;


int n, m;
char s[MAX_N], t[MAX_N];

int dp[MAX_N + 1][MAX_N + 1];

void slove() {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }

    cout<<dp[n][m];
}

