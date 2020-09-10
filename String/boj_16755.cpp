#include<iostream>
#include<string>

using namespace std;

int main(){
    string target = "HONI";
    int p = 0;

    string s; cin>>s;
    int count=0;
    for(int i=0; i<s.length();i++){
        if(s[i]==target[p]){
            p++;
            if(p==4)
                count++;
            p%=4;
        }
    }
    cout<<count<<endl;
    return 0;
}