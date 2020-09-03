#include<string>
#include<iostream>

using namespace std;

int main(){
    string a,b; cin>>a>>b;

    if(a.length()>b.length()){
        string in = "";
        for(int i=0; i<a.length()-b.length(); i++)
            in += '0';
        b.insert(0,in);
    }
    if(a.length()<b.length()){
        string in = "";
        for(int i=0; i<b.length()-a.length(); i++)
            in += '0';
        a.insert(0,in);
    }

    string res = "";
    for(int i=0; i<a.length(); i++){
        res += to_string(stoi(a.substr(i,1))+stoi(b.substr(i,1)));
    }
    cout<<res<<endl;

    return 0;
}