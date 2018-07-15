#include <cstdio>

const int MAX_W = 20;
const int MAX_H = 20;

//输入
int W, H;
int g[MAX_H][MAX_W];

//起始
int sx, sy;
//目标
int ex, ey;
//4个方向
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//最终结果
int result;

bool inSquare(int x, int y){
    return 0 <= x && x < H && 0 <= y && y < W;
}

//在(x, y)位置上的步数ans
void dfs(int x, int y, int ans){
    //若到达目标点
    if(x == ex && y == ey){
        if(result > ans){
            //若有更小值
            result = ans;
        }
        return;
    }
    //若超过10步，或超过当前最短步数
    if(ans == 10 || ans >= result) return;
    //深度优先4个方向走
    for(int i = 0; i < 4; i ++){
        int nx = x + d[i][0], ny = y + d[i][1];
        while(inSquare(nx, ny) && g[nx][ny] != 1){
            //若此方向能走，则走到尽头，直至出场或撞墙
            if(nx == ex && ny == ey){
                //若在过程中到达目标点
                ans ++;
                if(result > ans){
                    result = ans;
                }
                return;
            }
            nx += d[i][0];
            ny += d[i][1];
        }
        if((nx == x + d[i][0] && ny == y + d[i][1]) || !inSquare(nx, ny)){
            //此方向不能走，或出场
            continue;
        }
        //撞墙
        g[nx][ny] = 0;
        ans ++;
        dfs(nx - d[i][0], ny - d[i][1], ans);
        ans --;
        g[nx][ny] = 1;
    }
}

void solve(){
    //初始化
    result = 11;
    //找出起始点与终点
    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            if(g[i][j] == 2){
                sx = i;
                sy = j;
                g[i][j] = 0;
            }
            if(g[i][j] == 3){
                ex = i;
                ey = j;
            }
        }
    }
    //深度优先搜索
    dfs(sx, sy, 0);
    if(result == 11)
        printf("-1\n");
    else
        printf("%d\n", result);
}

int main(int argc, char const *argv[]){

    while(scanf("%d %d", &W, &H)){
        if(W == 0 && H == 0) break;
        for(int i = 0; i < H; i ++){
            for(int j = 0; j < W; j ++){
                scanf("%d", &g[i][j]);
            }
        }
        solve();
    }
    return 0;
}
