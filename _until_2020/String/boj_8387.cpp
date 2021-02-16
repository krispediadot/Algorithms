#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;
    string origin, s; cin>>origin>>s;

    int count=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==origin[i])
            count++;
    }
    cout<<count<<endl;

    return 0;
}