//
// Created by jchen on 18-7-4.
//

//有一个大小为N*M 的园子,雨后积水，求出共有多少个水洼

#define MAX_N 100
#define MAX_M 100

int n, m;

char field[MAX_N][MAX_M];

//深度遍历现在的位置(x,y)

void dfs(int x, int y) {
    //将当前位置替换为.
    field[x][y] = '.';
    //遍历8个方向
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;

            //判断新的坐标点是否越界，和是否是水，如果是水，继续dfs
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && field[nx][ny] == 'W')
                dfs(nx, ny);
        }
    }
}

int main() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    return res;
}