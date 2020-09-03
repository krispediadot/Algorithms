#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;cin>>s;

    int p = s.length()-3;
    while(p>0){
        s.insert(p,1,',');
        p -= 3;
    }
    cout<<s<<endl;

    return 0;
}