//蚂蚁爬杆子问题

#define MAX_N 1000000

int x[MAX_N];
int L, n;

void slove() {
    //计算最短时间
    int minT = 0;
    for (int i = 0; i < n; i++) {
        minT = max(minT, min(L - x[i], x[i]));
    }

    //计算最长时间
    int maxT = 0;
    for (int i = 0; i < n; i++) {
        maxT = max(maxT, max(L - x[i]), x[i]);
    }

    cout << minT << ' ' << maxT << endl;
}