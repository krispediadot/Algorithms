// https://www.acmicpc.net/problem/17626
// 17626. Four Squares
//
// input
// 25
// output
// 1
//
// input
// 26
// output
// 2
//
// input
// 11339
// output
// 3
//
// input
// 34567
// output
// 4
//

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> nums;

int min(int a, int b){return a<b?a:b;}

int main(){
    int n; cin>>n;

    for(int i=0; i<=n; i++) nums.push_back(i);
    for(int i=0; i<=(int)sqrt(n); i++) nums[i*i] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=(int)sqrt(i); j++){
            nums[i] = min(nums[i], nums[j*j]+nums[i-j*j]);
        }
    }

    cout<<nums[n];
}
