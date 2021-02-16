#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;cin>>n;
    for(int i=0; i<n; i++){
        string s;cin>>s;
        for(int index=0; index<s.length(); index++){
            if(s[index]<='Z') cout<<char(s[index]+('a'-'A'));
            else cout<<s[index];
        }
        cout<<endl;
    }
    return 0;
}