#include<iostream>
#include<string>

using namespace std;

int main(){
    int c[2][26]={0};
    string a,b; cin>>a>>b;
    int res = 0;

    for(int i=0; i<a.length(); i++)
        c[0][a[i]-'a']++;
    for(int i=0; i<b.length(); i++)
        c[1][b[i]-'a']++;

    for(int i=0; i<26; i++){
        int max = c[0][i]>c[1][i]?c[0][i]:c[1][i];
        res += (max-c[0][i]);
        res += (max-c[1][i]);
    }
    cout<<res<<endl;

    return 0;
}