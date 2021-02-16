#include<iostream>
#include<string>

using namespace std;

int main(){
    long long n, k; cin>>n>>k;
    string s; cin>>s;
    long long gap = n/4;
    k %= 3;
    for(long long i=0; i<k; i++){
        string s1 = s.substr(0, gap);
        string s2 = s.substr(gap*1, gap);
        string s3 = s.substr(gap*2, gap);
        string s4 = s.substr(gap*3, gap);

        s = s1+s4+s2+s3;
    }

    cout<<s<<endl;

    return 0;
}