// https://www.acmicpc.net/problem/14916
// 14916. 거스름돈
//
// input
// 13
// output
// 5
//
// input
// 14
// output
// 4
//

#include<iostream>
#define MAX 100001
using namespace std;

int coins[MAX];

int min(int a, int b) {return a<b?a:b;}

int main(){
    int n; cin>>n;
    for(int i=0; i<=n; i++) coins[i] = MAX;

    for(int i=0; i<=n; i+=5) coins[i] = min(i/5, coins[i]);
    for(int i=0; i<=n; i+=2) coins[i] = min(i/2, coins[i]);
    for(int i=0; i<=n; i+=5){
        for(int j=0; i+j<=n; j+=2){
            coins[i+j] = min(coins[i]+coins[j], coins[i+j]);
        }
    }
    if(coins[n]==MAX) cout<<-1;
    else cout<<coins[n];
}
