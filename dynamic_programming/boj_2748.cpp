// https://www.acmicpc.net/problem/2748
// 2748. 피보나치 수 2
//
// input
// 10
//
// output
// 55
//

#include<iostream>

using namespace std;

int main(){
    int n;cin>>n;
    long long f1 = 0;
    long long f2 = 1;
    long long f3;
    int idx = 2;
    while(idx<=n){
        f3 = f2+f1;
        f1 = f2;
        f2 = f3;
        idx++;
    }
    if(n==0) cout<<0;
    else if(n==1) cout<<1;
    else cout<<f3;
}
