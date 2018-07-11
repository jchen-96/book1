#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>


//aoj 0121  广度优先搜索
//将一组数字看作一个状态，遍历所有的状态空间，放在res中

//采用广度优先搜索，一般都是由近及远的进行搜索

//note :这个题看起来不像是广度优先搜索，是一个逆向过程，先宽度优先搜索所有状态和初始状态的距离

using namespace std;
int d[4] = {1, -1, 4, -4};

map<string, int> res;


//用于存储所有状态空间

void slove() {

    queue<string> que;
    que.push("01234567");

    while (!que.empty()) {
        string s = que.front();
        que.pop();

        //pos用于记录其中0的位置
        int pos;
        for (int i = 0; i < 8; i++) {
            if (s[i] == '0')
                pos = i;
        }
        for(int i=0;i<4;i++){
            if(pos+d[i]>=0&&pos+d[i]<8&&!(pos==3&&i==0)&&!(pos==4&&i==1)){
                string u=s;
                swap(u[pos],u[pos+d[i]]);

                if(res[u]==0){
                    que.push(u);
                    res[u]=res[s]+1;
                }

            }
        }

    }

}

int main() {
    int in;
    res["01234567"] = 1;

    slove();

    while (true) {
        string s;
        for (int i = 0; i < 8; i++) {
            if (!(cin >> in)) return 0;

            s += in + '0';
        }

        cout << res[s] - 1 << endl;
    }

    return 0;

}
