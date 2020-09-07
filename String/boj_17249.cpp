#include<iostream>
#include<string>

using namespace std;

int main(){
    string s; cin>>s;
    bool left = true;
    int l=0,r=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') left = false;
        if(s[i]=='@' && left) l++;
        else if(s[i]=='@' && !left) r++;
    }
    cout<<l<<" "<<r<<endl;

    return 0;
}