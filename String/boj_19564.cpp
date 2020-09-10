#include<iostream>
#include<string>
using namespace std;

int main(){
    int count=1;
    string s; cin>>s;
    for(int i=1; i<s.length(); i++){
        if(s[i]<=s[i-1]){
            count++;
        }
    }
    cout<<count<<endl;

}