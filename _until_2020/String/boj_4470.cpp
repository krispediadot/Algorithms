#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    cin.ignore();
    for(int i=1; i<=n; i++){
        string s; getline(cin, s);
        cout<<i<<". "<<s<<endl;
    }

    return 0;
}