#include<iostream>
#include<string>

using namespace std;

int main(){
    string s; cin>>s;
    bool palindrome = true;
    for(int i=0; i<s.length()/2; i++){
        if(s[i]!=s[s.length()-1-i]) {
            palindrome = false;
            break;
        }
    }
    cout<<palindrome<<endl;
}