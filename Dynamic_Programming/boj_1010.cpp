#include<iostream>
#define SIZE 30

using namespace std;

int dp[SIZE][SIZE] = {0};

int sol(int i, int j){
    if(dp[i][j]!=0)
        return dp[i][j];
    else if(i==j){
        dp[i][j] = 1;
        return dp[i][j];
    }
    else if(i==1){
        dp[i][j] = j;
        return dp[i][j];
    }
    else{
        int sum = 0;
        for(int k=j; k>=i; --k)
            sum += sol(i-1, k-1);
        dp[i][j] = sum;
        return dp[i][j];
    }
}

int main(void){
    int T;
    int N, M;

    cin>>T;

    for(int t=0; t<T; ++t){
        cin>>N>>M;

        cout<<sol(N,M)<<endl;

    }
    return 0;
}
