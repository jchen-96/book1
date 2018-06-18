//有n个棍子，选出三个组成周长尽可能长的三角形。输出周长，无法构成三角形则输出0
//三个数能组成三角形的充要条件是　最长棍子的长度<其余两根棍子的长度之和


//三重循环
#define MAX_N 100

int n, a[MAX_N];

void slove() {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int len=a[i]+a[j]+a[k];
                int ma=max(a[i],max(a[j],a[k]));
                int rest=len-ma;

                if(ma<rest){
                    ans=max(ans,len);
                }
            }
        }
    }

    cout<<ans<<endl;
}