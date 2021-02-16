#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main(){
    string s; getline(cin, s);
    regex reA("[A-Z]");
    regex rea("[a-z]");
    for(int i=0; i<s.length(); i++){
        if(regex_match(s.substr(i,1), reA)){
            cout<<char((s[i]-'A'+13)%26+'A');
        }
        else if(regex_match(s.substr(i,1), rea)){
            cout<<char((s[i]-'a'+13)%26+'a');
        } else
            cout<<s[i];
    }
}