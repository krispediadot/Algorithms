#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    string s; getline(cin, s);

    string target = "UCPC";
    int p = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i]==target[p])
            p++;
    }
    if(p==4) cout<<"I love UCPC"<<endl;
    else cout<<"I hate UCPC"<<endl;
}