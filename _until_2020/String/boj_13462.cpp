#include<iostream>
#include<string>

using namespace std;

int main(){
    string s; cin>>s;
    string ans = "";
    int p = 0;

    while(p<s.length()){
        if(p<(s.length()-2) && (s[p]+s[p+1]+s[p+2]) == ('R'+'B'+'L')){
            ans += "C";
            p +=3;
        }
        else{
            if(s[p]=='R')
                ans += "S";
            else if(s[p]=='B')
                ans += "K";
            else if(s[p]=='L')
                ans += "H";

            p += 1;
        }
    }
    cout<<ans<<endl;

    return 0;
}