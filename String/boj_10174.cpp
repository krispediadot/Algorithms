#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n; cin.ignore();
    string s;

    for(int i=0; i<n; i++){
        bool res = true;
        getline(cin, s);
        for(int index=0; index<s.length(); index++){
            if(s[index]==s[s.length()-1-index] || s[index]-s[s.length()-1-index]=='a'-'A' || s[s.length()-1-index]-s[index]=='a'-'A')
                continue;
            res = false;
            break;
        }
        if(res) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}