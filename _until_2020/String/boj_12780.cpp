#include<iostream>
#include<string>

using namespace std;

int main(){
    string s, target; cin>>s>>target;

    int count=0;
    while(s.find(target)!=string::npos){
        count++;
        s = s.substr(s.find(target)+1);
    }
    cout<<count<<endl;

    return 0;
}