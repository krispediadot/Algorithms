#include <iostream>
#include <string>

using namespace std;

int main() {
    string s,t;
    getline(cin, s);
    getline(cin,t);
    string a = "";

    for(int i=0; i<s.length(); i++){
        int term = t[i%t.length()]-'a'+1;
        if(s[i]==' ')
            a+=' ';
        else if(s[i]-term <'a'){
            a+=char(s[i]-term+26);
        }
        else{
            a+=char(s[i]-term);
        }
    }
    cout<<a<<endl;

    return 0;
}