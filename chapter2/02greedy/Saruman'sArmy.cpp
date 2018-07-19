//
// Created by Administrator on 2018/7/14 0014.
// poj 3069 贪心


#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1010];

int main() {
    int n, R;

    while (scanf("%d %d", &R, &n) && R != -1 && n != -1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int res = 0;

        sort(a, a + n);

        int i = 0, ans = 0;
        while (i < n) {
            int s = a[i];
            while (i < n && a[i] <= s + R)
                i++;
            int p = a[i - 1];

            while (i < n && a[i] <= p + R)
                i++;
            res++;
        }

        printf("%d\n", res);
    }

    return 0;
}
