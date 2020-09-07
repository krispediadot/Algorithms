#include<iostream>
#include<string>

using namespace std;

int main(){
    while(1){
        string s; cin>>s;
        if(s=="0") break;

        bool palindrome = true;

        for(int i=0; i<s.length()/2; i++){
            if(s[i]!=s[s.length()-1-i]){
                palindrome = false;
                break;
            }
        }
        if(palindrome) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}