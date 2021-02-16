#include<iostream>
#include<string>

using namespace std;

int main(){
    string s; cin>>s;

    string left = s.substr(0, s.length()/2);
    string right = s.substr(s.length()/2, s.length()/2);

    int l=0,r=0;
    for(int i=0; i<s.length()/2; i++){
        l+=stoi(left.substr(i,1));
        r+=stoi(right.substr(i,1));
    }
    if(l==r)
        cout<<"LUCKY"<<endl;
    else
        cout<<"READY"<<endl;

    return 0;
}