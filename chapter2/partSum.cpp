//
// Created by jchen on 18-6-20.
//


//给定若干整数，判断是否是否可以从中选出若干数，使其和为k
#define MAX_N 20

#include <iostream>

using namespace std;

int n,k[MAX_N],s;


//从k[i]开始，能否组成和为sum
bool slove(int i,int sum){
    if(i>=n)
        return false;

    if(k[i]==sum)
        return true;
    else if (k[i]>sum)
        return false;
    else
        return slove(i+1,sum-k[i])||slove(i+1,sum);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    cin>>s;
    if(slove(0,s))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

