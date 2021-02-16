#include<iostream>
#define MAX 12
using namespace std;

int op[4] = {0,};
int num[MAX];
int n, minRes=1000000000, maxRes=-1000000000;

void getInput(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>num[i];
    for(int i=0; i<4; i++) cin>>op[i];
}
void doOperation(int cnt, int res){
    if(cnt==n-1){
        minRes = minRes<res?minRes:res;
        maxRes = maxRes>res?maxRes:res;
        return;
    }
    if(op[0]>0) {op[0]--; doOperation(cnt+1, res+num[cnt+1]); op[0]++;}
    if(op[1]>0) {op[1]--; doOperation(cnt+1, res-num[cnt+1]); op[1]++;}
    if(op[2]>0) {op[2]--; doOperation(cnt+1, res*num[cnt+1]); op[2]++;}
    if(op[3]>0) {
        int tmp;
        op[3]--;
        if(res<0) {tmp = (res*-1)/num[cnt+1]; tmp *= -1;}
        else tmp = res/num[cnt+1];
        doOperation(cnt+1, tmp);
        op[3]++;
    }
}
int main(){
    getInput();
    doOperation(0, num[0]);
    cout<<maxRes<<endl;
    cout<<minRes<<endl;
}