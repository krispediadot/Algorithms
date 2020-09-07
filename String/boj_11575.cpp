#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;
    for(int t=0; t<n; t++){
        int a, b; cin>>a>>b;
        string s; cin>>s;
        string ans = "";
        for(int i=0; i<s.length(); i++){
            ans += char(((a*(s[i]-'A') +b)%26)+'A');
        }
        cout<<ans<<endl;
    }

    return 0;
}