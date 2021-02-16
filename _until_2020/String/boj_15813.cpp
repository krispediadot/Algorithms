#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    int res = 0;

    for(int i=0; i<s.length(); i++){
        res += (s[i]-'A'+1);
    }
    cout<<res<<endl;

    return 0;
}