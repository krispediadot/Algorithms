#include<string>
#include<iostream>
#include<regex>

using namespace std;

int main(){
    string s;
    regex re("joke");
    int count=0;
    while(cin>>s){
        int p=0;
        while(p+4<=s.length()){
            if(regex_match(s.substr(p,4),re))
                count++;
            p++;
        }
    }
    cout<<count<<endl;

    return 0;
}