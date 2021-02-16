#include<iostream>

using namespace std;

int main(){
    string s; getline(cin,s);
    string ans = "";
    int i = 0;
    while(i<s.length()){
        if((i<s.length()-2) && (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') && s[i+1]=='p' && s[i+2]==s[i]){
            ans += s[i];
            i+=3;
        } else
            ans+=s[i++];
    }

    cout<<ans<<endl;

    return 0;
}