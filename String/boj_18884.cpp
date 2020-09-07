#include<iostream>
#include<string>
#define MAX 20
using namespace std;

int main(){
    int ns, nt; cin>>ns>>nt;
    string s[MAX];
    string t[MAX];

    for(int i=0; i<ns; i++) cin>>s[i];
    for(int i=0; i<nt; i++) cin>>t[i];

    int q; cin>>q;
    for(int i=0; i<q; i++){
        int year; cin>>year;
        cout<<s[(year-1)%ns]<<t[(year-1)%nt]<<endl;
    }

    return 0;
}