#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, m; cin>>n>>m;
    int count=0;
    for(int t=0; t<n; t++){
        bool c[26]={false,};
        bool able = true;
        string s;cin>>s;
        for(int i=0; i<s.length(); i++){
            if(s[i]-'A'>=m || c[s[i]-'A']==true) {
                able = false;
                break;
            }
            c[s[i]-'A'] = true;
        }
        if(able) count++;
    }
    cout<<count<<endl;

    return 0;
}