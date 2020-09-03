#include<iostream>
#include<string>
#define SIZE 80

using namespace std;

int main(){
    int t;cin>>t;

    for(int tt=0; tt<t; tt++){
        int arr[SIZE]={0,};
        string s; cin>>s;

        if(s[0]=='O') arr[0] = 1;
        for(int i=1; i<s.length(); i++){
            if(s[i]=='O')
                arr[i] = arr[i-1]+1;
        }

        int sum=0;
        for(int i=0; i<s.length(); i++) sum+=arr[i];
        cout<<sum<<endl;
    }

    return 0;
}