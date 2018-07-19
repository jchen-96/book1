//
// Created by Administrator on 2018/7/14 0014.
//   poj 3253 以最小的代价切木板

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, L[20005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    long long  res = 0;
    sort(L, L + N);
    for (int i = 0; i < N - 1; i++) {
        res += L[i];
        res += L[i + 1];
        L[i + 1] = L[i] + L[i + 1];
        int temp = L[i + 1];
        int k = i + 1;
        while (k + 1 < N && temp > L[k + 1]) {
            L[k] = L[k + 1];
            k++;
        }
        L[k] = temp;
    }

    printf("%lld\n", res);
    return 0;
}