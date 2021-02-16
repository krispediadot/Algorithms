#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
    int res[26];
    memset(res, -1, sizeof(int)*26);
    string s; cin>>s;

    for(int i=0; i<s.length(); i++){
        if(res[int(s[i])-'a']==-1)
            res[int(s[i])-'a'] = i;
    }
    for(int i=0; i<26; i++)
        cout<<res[i]<<" ";

    return 0;
}