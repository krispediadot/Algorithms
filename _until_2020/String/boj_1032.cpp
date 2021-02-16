#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;
    string ans = "";

    for(int i=0; i<n; i++){
        string s; cin>>s;
        if(i==0) ans = s;
        else{
            for(int i=0; i<s.length(); i++){
                if(s[i]!=ans[i]) ans[i] = '?';
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}