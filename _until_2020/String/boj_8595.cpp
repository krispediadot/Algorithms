#include<iostream>
#include<string>

using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;

    long long sum=0;
    int p = 0;
    while(p<s.length()){
        if(s[p]>='0' && s[p]<='9'){
            int num = s[p]-'0';
            p++;
            while((s[p]>='0' && s[p]<='9')){
                num *=10;
                num += s[p]-'0';
                p++;
            }
            sum += num;
        }
        else
            p++;
    }

    cout<<sum<<endl;

    return 0;
}