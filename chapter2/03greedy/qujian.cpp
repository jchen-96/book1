// 有n 项工作，每项工作有起始时间和结束时间，同时只能做一件工作，要使得做的工作的项数最多


//贪心策略，尽量做结束的早的工作


#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_N = 100000;

int N, S[MAX_N], T[MAX_N];

pair<int, int> itv[MAX_N];

void slove() {
    for (int i = 0; i < N; i++) {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }

    sort(itv, itv + N);

    int ans = 0, t = 0;

    for (int i = 0; i < N; i++) {
        if (t < itv[i].second) {
            ans++;
            t = itv[i].first;
        }
    }

    cout << ans << endl;
}
