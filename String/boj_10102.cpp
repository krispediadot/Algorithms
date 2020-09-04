#include<string>
#include<iostream>

using namespace std;

int main(){
    int c[2]={0,};
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0; i<n; i++){
        if(s[i]=='A')
            c[0]++;
        else if(s[i]=='B')
            c[1]++;
    }
    if(c[0]>c[1])
        cout<<"A"<<endl;
    else if(c[0]<c[1])
        cout<<"B"<<endl;
    else
        cout<<"Tie"<<endl;

    return 0;
}