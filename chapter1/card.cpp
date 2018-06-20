//
// Created by jchen on 18-6-19.
//
// 给定一组数和m,是否存在四个数的和（可重复选取）为m

//#define MAX_N 100;

int n, k[MAX_N], m;

//暴力求解，四层循环

bool slove1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int m = 0; m < n; m++) {
                for (int p = 0; p < n; p++) {
                    if (k[i] + k[j] + k[m] + k[p] == m) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


//采用二分查找，三层循环
bool binary_search(int x) {
    int l = 0, r = n;

    while (l < r) {
        int mid = (l + r) / 2;

        if (k[mid] == x) return true;

        else if (k[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}


void slove2() {
    sort(k, k + n);

    bool f = false;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            for (int c = 0; c < n; c++) {
                if (binary_search(m - k[a] - k[b] - k[c])) {
                    f = true;
                }
            }
        }
    }

    if (f)
        cout << "Yes";
    else
        cout << "No";
}


//O(n*nLog(n)) 级别的算法

int kk[MAX_N * MAX_N];//保存两个数的和的数组


bool b_search(int x) {
    int l = 0, r = n * n;

    while (l < r) {
        int mid = (l + r) / 2;

        if (kk[i] == x) {
            return true;
        } else if (kk[i] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
}


void slove4() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            kk[count] = k[i] + k[j];
        }
    }

    sort(kk, kk + n * n);

    bool f = false;
    for (int a = 0; a < n; i++) {
        for (int b = 0; b < n; b++) {
            if (b_search(m - k[a] - k[b])) {
                f = true;
            }
        }
    }
    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

