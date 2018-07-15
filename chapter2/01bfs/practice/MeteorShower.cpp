#include <cstdio>
#include <queue>
#include <cstdio>

//poj 3669

using namespace std;


int d[4][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
};


#define Max_V 10000000
typedef pair<int, int> P;

int M;

int strike[305][305];
int wt[305][305];

bool inArea(int x, int y) {
    return x >= 0 && y >= 0;
}


int bfs() {
    queue<P> queue;
    if (strike[0][0] == 0) {
        return -1;
    }
    wt[0][0] = 0;
    queue.push(P(0, 0));
    while (!queue.empty()) {
        P p = queue.front();
        queue.pop();
        if (strike[p.first][p.second] == Max_V) {
            return wt[p.first][p.second];
        }

        for (int i = 0; i < 4; i++) {
            int s_t = wt[p.first][p.second] + 1;
            int nx = p.first + d[i][0];
            int ny = p.second + d[i][1];

            if (inArea(nx, ny) && wt[nx][ny] == Max_V && strike[nx][ny] > s_t) {
                wt[nx][ny] = s_t;
                queue.push(P(nx, ny));
            }
        }

    }
    //搜索完成没有结果，返回-1
    return -1;

}

int main() {
    scanf("%d", &M);
    int x, y, t;

    for (int i = 0; i < 305; i++) {
        for (int j = 0; j < 305; j++) {
            strike[i][j] = Max_V;
            wt[i][j] = Max_V;
        }
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &x, &y, &t);
        strike[x][y] = min(strike[x][y], t);
        for (int j = 0; j < 4; j++) {
            int nx = x + d[j][0];
            int ny = y + d[j][1];
            if (inArea(nx, ny)) {
                strike[nx][ny] = min(strike[nx][ny], t);
            }
        }

    }

    printf("%d\n", bfs());

}
