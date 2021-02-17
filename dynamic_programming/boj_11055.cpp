//https://www.acmicpc.net/problem/11055
// 11055.가장 큰 증가 부분 수열
//
// input
// 10
// 1 100 2 50 60 3 5 6 7 8
// output
// 113
//
// input
// 10
// 1 100 2 100 50 60 70 80 90 100
// output
// 453

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> arr;
    vector<int> dp;
    int answer = 0;

    for(int i=0; i<n; i++){
        int in; cin>>in;
        arr.push_back(in);
        dp.push_back(in);
        for(int j=0; j<dp.size(); j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+arr[i]){
                dp[i] = dp[j]+arr[i];
            }
        }
        answer = dp[i]>answer?dp[i]:answer;
    }
    
    cout<<answer;
}