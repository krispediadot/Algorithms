#include<iostream>
#define SIZE 100
#define MAX 10001

using namespace std;

int main(void){
    int dp[MAX] = {0};
    int c[SIZE];
    int n, k;

    cin>>n>>k;

    for(int i=0; i<n; ++i)
        cin >> c[i];

    // base
    dp[0] = 1;

    for(int i=0; i<n; ++i){
        for(int j=c[i]; j<=k; ++j) {
            if (j - c[i] >= 0)
                dp[j] += dp[j - c[i]];
        }
    }
    cout<<dp[k]<<endl;

    return 0;
}
