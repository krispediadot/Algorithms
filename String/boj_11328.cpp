#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;

    for(int t=0; t<n; t++){
        int c[26]={0,};
        string a,b; cin>>a>>b;
        for(int i=0; i<a.length(); i++){
            c[a[i]-'a']++;
        }
        bool possible = true;
        for(int i=0; i<b.length(); i++){
            c[b[i]-'a']--;
            if(c[b[i]-'a']<0)
                possible = false;
        }
        for(int i=0; i<26; i++) {
            if (c[i] != 0)
                possible = false;
        }
        if(possible) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }

    return 0;
}