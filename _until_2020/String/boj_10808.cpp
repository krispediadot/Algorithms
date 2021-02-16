#include<iostream>
#include<string>

using namespace std;

int main(){
    int res[26] = {0,};
    string s; cin>>s;

    for(int i=0; i<s.length(); i++){
        res[int(s[i])-'a']++;
    }
    for(int i=0; i<26; i++)
        cout<<res[i]<<" ";

    return 0;
}