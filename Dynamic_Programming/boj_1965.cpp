#include<iostream>
#define SIZE 1001
using namespace std;

int main(){
    int arr[2][SIZE]={0};
    int dp[SIZE]={0};
    int n;
    cin>>n;
    int max = 0;
    for(int i=0; i<n; i++){
        cin>>arr[0][i];
        if(arr[0][i]>max)
            max = arr[0][i];
    }
    dp[1] = arr[0][0];
    arr[1][0] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = max;
    }
    for(int i=1; i<n; i++){
        int checkNum = arr[0][i];
        int checkIndex=0;
        for(int index=1; index<n; index++){
            if(checkNum>dp[index]&&checkNum<=dp[index+1]){
                checkIndex = index;
                break;
            }
        }
        dp[checkIndex+1] = checkNum;
        arr[1][i] = checkIndex+1;
    }

    max = 0;
    for(int i=0; i<n; i++){
        if(arr[1][i]>max)
            max = arr[1][i];
    }
    cout<<max<<endl;


    return 0;
}
