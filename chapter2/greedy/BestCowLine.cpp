#include <iostream>
#include <string>
#include <cstdio>

//  poj 3617

#define MAX_N 2005

using namespace std;
char s[MAX_N];
string t;
int N;

int main() {
    cin>>N;

    for (int i = 0; i < N; i++) {
        cin>>s[i];
    }


    int i = 0, j = N - 1;
    while (i <= j) {
        if (s[i] < s[j]) {
            t = t + s[i];
            i++;
        } else if (s[i] > s[j]) {
            t = t + s[j];
            j--;
        } else {
            int m = i, n = j;
            while (s[m] == s[n] && m <= n) {
                m++;
                n--;
            }
            if (m >= n) {
                t = t + s[i];
                i++;
            } else if (s[m] < s[n]) {
                t = t + s[i];
                i++;
            } else {
                t = t + s[j];
                j--;
            }
        }
    }

    for(int i=0;i<N;i++){
        if(i>0&&i%80==0)
            cout<<endl;
        cout<<t[i];
    }

    return 0;
}
