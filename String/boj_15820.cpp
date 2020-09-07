#include<iostream>
#include<string>
#define MOD 1234567891
#define MULTIPLE 31

using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;

    long long sum = 0;
    long long R = 1;
    for(int i=0; i<s.length(); i++){
        sum += ((s[i]-'a'+1)*R)%MOD;
        R = (R*MULTIPLE) %MOD;
    }
    cout<<sum%MOD<<endl;

    return 0;
}