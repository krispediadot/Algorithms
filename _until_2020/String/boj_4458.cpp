#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;
    cin.ignore();

    for(int i=0; i<n; i++){
        string s;getline(cin, s);

        if(s[0]>'Z') cout<<char(s[0]-('a'-'A'));
        else cout<<s[0];
        for(int i=1; i<s.length(); i++){
            cout<<s[i];
        }
        cout<<endl;
    }

    return 0;
}