#include<iostream>
#include<string>
using namespace std;

int main(){
    int count=0;
    for(int i=1; i<=8; i++){
        string s;
        cin>>s;
        for(int j=0; j<8; j++){
            if(s[j]=='F' && (i+j)%2==1)
                count++;
        }
    }
    cout<<count<<endl;

    return 0;
}