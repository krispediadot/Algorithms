#include<string>
#include<iostream>

using namespace std;

int main(){
    int n; cin>>n;
    for(int t=0; t<n; t++){
        string s;cin>>s;
        cout<<s[0]<<s[s.length()-1]<<endl;
    }

    return 0;
}