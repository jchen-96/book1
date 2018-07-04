//
// Created by jchen on 18-7-4.
//　Read and Black 杭电oj

#include <iostream>

#define MAX_W 20
#define MAX_H 20

using namespace std;

int w, h;

char field[MAX_W][MAX_H];

int res = 0;
int a[4][2] = {{0,  -1},
               {0,  1},
               {1,  0},
               {-1, 0}};

void dfs(int x, int y) {
    res++;
    field[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        int nx = x + a[i][0];
        int ny = y + a[i][1];

        if (nx >= 0 && nx < h && ny >= 0 && ny < w && field[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }

}

int main() {
    while (cin >> w >> h) {
        res=0;
        if(w==0&&h==0)
            break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> field[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (field[i][j] == '@') {
                    dfs(i, j);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}


