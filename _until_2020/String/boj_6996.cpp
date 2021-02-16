#include<iostream>
#include<string>

using namespace std;

int main(){
    int t; cin>>t;

    for(int tt=0; tt<t; tt++){
        int c[26] = {0,};
        string a,b;cin>>a>>b;

        for(int i=0; i<a.length(); i++){
            c[a[i]-'a']++;
        }
        bool ok = true;
        for(int i=0; i<b.length(); i++){
            c[b[i]-'a']--;
            if(c[b[i]-'a']<0)
                ok = false;
        }
        for(int i=0; i<26; i++){
            if(c[i]!=0)
                ok = false;
        }
        if(ok)
            cout<<a<<" & "<<b<<" are anagrams."<<endl;
        else
            cout<<a<<" & "<<b<< " are NOT anagrams."<<endl;
    }
}