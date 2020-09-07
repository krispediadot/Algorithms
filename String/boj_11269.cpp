#include<iostream>
#include<string>

using namespace std;

int main(){
    string name = "PER";
    string s; cin>>s;

    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]!=name[i%3]) {
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}