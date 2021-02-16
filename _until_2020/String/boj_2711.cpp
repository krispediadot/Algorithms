#include<string>
#include<iostream>

using namespace std;

int main(){
    int T; cin>>T;
    for(int t=0; t<T; t++){
        int n;cin>>n;
        string s;cin>>s;
        string res = "";

        res+=s.substr(0, n-1);
        res+=s.substr(n, s.length()-n+1);

        cout<<res<<endl;
    }

    return 0;
}