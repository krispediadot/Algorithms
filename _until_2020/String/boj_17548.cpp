#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;cin>>s;

    int len = s.length()-2;

    cout<<"h"<<s.substr(1,s.length()-2)<<s.substr(1,s.length()-2)<<"y"<<endl;

    return 0;
}