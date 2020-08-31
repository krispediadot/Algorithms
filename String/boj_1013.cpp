#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        cout<<(regex_match(s, regex("(100+1+|01)+"))?"YES\n":"NO\n");
    }

    return 0;
}