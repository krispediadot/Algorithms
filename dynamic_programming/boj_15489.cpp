// https://www.acmicpc.net/problem/15489
// 15489. 파스칼 삼각형
//
//input
//3 1 4
//output
//42
//

#include<iostream>
#include<cstring>
#define MAX 31
using namespace std;

int nums[MAX][MAX];

int main(){
    memset(nums, 0, sizeof(nums));
    int r,c,w; cin>>r>>c>>w;
    int tempc = c;
    while(--tempc) r--;

    for(int i=1; i<r+w; i++){
        for(int j=1; j<c+w; j++){
            if(i==1 || j==1) nums[i][j] = 1;
            else
                nums[i][j] = nums[i-1][j]+nums[i][j-1];
        }
    }

    int sum = 0;
    int term = w;
    for(int i=r; i<r+w; i++){
        for(int j=c; j<c+term; j++){
            sum+=nums[i][j];
        }
        term--;
    }
    cout<<sum;
}
