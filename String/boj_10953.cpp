#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        cout<<stoi(s.substr(0,1))+stoi(s.substr(2,1))<<endl;
    }


    return 0;
}