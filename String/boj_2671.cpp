#include<string>
#include<iostream>
#include<regex>

using namespace std;

int main(){
    string s;cin>>s;
    regex re("((100+1+)|(01))+");

    if(regex_match(s,re))
        cout<<"SUBMARINE"<<endl;
    else
        cout<<"NOISE"<<endl;

    return 0;
}