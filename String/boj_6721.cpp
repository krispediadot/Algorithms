#include<iostream>
#include<string>

using namespace std;

int reverse(string s){
    string sub="";

    sub+=s[s.length()-1];
    while(s.length()>0){
        s = s.substr(0,s.length()-1);
        sub+=s[s.length()-1];
    }

    return stoi(sub.substr(0, sub.length()-1));
}

int main(){
    int n;cin>>n;
    for(int i=0; i<n; i++) {
        string a, b; cin >> a >> b;

        int res = reverse(a)+reverse(b);
        cout<<reverse(to_string(res))<<endl;
    }

    return 0;
}