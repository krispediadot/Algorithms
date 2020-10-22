#include<iostream>
#include<string>
#include<climits>
using namespace std;
int n;
string in;
int ans = INT_MIN;

int calculator(int a, int b, char opt){
    if(opt == '+') return a+b;
    if(opt == '-') return a-b;
    if(opt == '*') return a*b;
}
void dfs(int idx, int res){
    if(idx > n){
        ans = res>ans?res:ans;
        return;
    }
    // 괄호 추가 안하기
    dfs(idx+2, calculator(res, int(in[idx])-'0', in[idx-1]));
    // 괄호 추가 하기
    if(n-idx>=2)
        dfs(idx+4, calculator(res,calculator(int(in[idx])-'0',int(in[idx+2])-'0', in[idx+1]), in[idx-1]));
}
int main(){
    cin>>n; cin>>in;
    in.insert(in.begin(),'+');
    dfs(1,0);
    cout<<ans<<endl;

    return 0;
}