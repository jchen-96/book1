//
// Created by Administrator on 2018/7/16 0016.
//  多重部分和问题
//有n种大小 不同的数字，每种各M(i)个，判断是否可以从这些数字中选出若干使得他们的和恰好为k

#include <iostream>
#include <algorithm>

#define Max_N 105
#define Max_V 100000

using namespace std;

int n,K;

int a[Max_N],m[Max_N];

bool dp[Max_N][Max_V];

int main(){
    dp[0][0]= true;

    for(int i=0;i<n;i++){
        for(int j=0;j<=K;j++){
            for(int k=0;k<=m[i]&&k*a[i]<=j;k++){
                dp[i+1][j]=dp[i+1][j]||dp[i][j-k*a[i]];
            }
        }
    }
    return 0;
}

