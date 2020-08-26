#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int c[2]={0};
    for(int i=0; i<s.length(); i++){
        if(s[i]=='S') c[0]++;
        else c[1]++;
    }
    int res = c[0]+c[1]/2+1;
    if(res>n) res = n;
    cout<<res<<endl;
    return 0;
}