#include<iostream>
#include<string>
#include<regex>
#include<vector>

using namespace std;

int main(){
    string s;cin>>s;
    for(int i=0; i<s.length(); i++) if(s[i]=='*') s.replace(i,1,".");
    regex re(s);
    int n;cin>>n;

    vector<string> ans;

    for(int i=0; i<n; i++){
        string in;cin>>in;
        if(regex_match(in, re))
            ans.push_back(in);
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<endl;

    return 0;
}