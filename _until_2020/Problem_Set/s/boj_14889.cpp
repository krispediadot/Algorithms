#include<iostream>
#define MAX 20
using namespace std;

int arr[MAX][MAX];
bool flag[MAX] = {false,};
int n, minGap = 200;

void getInput(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
}
int oppositeTeam(bool mode){
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(flag[i]==mode && flag[j]==mode){
                res += arr[i][j];
                res += arr[j][i];
            }
        }
    }
    return res;
}
int lastIndex(){
    for(int i=n-1; i>0; i--){
        if(flag[i]==true)
            return i;
    }
    return NULL;
}
void getMinGap(int cnt){
    if(cnt == n/2){
        int sub = oppositeTeam(true)-oppositeTeam(false);
        if(sub<0) sub*=-1;
        minGap = minGap<sub?minGap:sub;
        return;
    }
    for(int i=lastIndex(); i<n; i++){
        if(flag[i]==false) {
            flag[i] = true;
            getMinGap(cnt + 1);
            flag[i] = false;
        }
    }
}
int main(){
    getInput();
    getMinGap(0);
    cout<<minGap;
}