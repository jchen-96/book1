#include <iostream>
//硬币问题
//有1,5,10,50,100,500 等面值的硬币各C[i] 枚
//求解最少用多少硬币可以组成A元

using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};

int C[6];

int A;

void slove() {
    int ans = 0;

    for (int i = 5; i >= 0; i--) {
        int t = min(A / V[i], C[i]);
        A -= t * V[i];

        ans += t;
    }

    cout << ans << endl;
}
