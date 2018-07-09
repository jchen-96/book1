#include <iostream>
#include <queue>

#define MAX_N 100
#define MAX_M 100

//给定一个N*M 的迷宫，找出最短路径,S 为起点，G为终点

using namespace std;

const int INF = 100000000;

typedef pair<int, int> P;

char maze[MAX_N][MAX_M + 1];

int N, M;

int sx, sy;
int gx, gy;

int d[MAX_N][MAX_M];

int dx[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int bfs() {
    queue<P> que;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            d[i][j] = INF;
        }
    }

    que.push(P(sx, sy));

    d[sx][sy] = 0;

    while (!que.size()) {
        P p = que.front();
        que.pop();

        if (p.first == gx && p.second == gy) break;

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i][0];
            int ny = p.second + dx[i][1];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(P(nx, ny));

                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

void slove() {
    int res = bfs();
    printf("%d\n", res);
}


int main() {
    while (cin >> N >> M) {
        if (N && M)
            break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (maze[i][j] == 'G') {
                    gx = i;
                    gy = j;
                }
            }
        }
    }
    slove();

    return 0;
}
