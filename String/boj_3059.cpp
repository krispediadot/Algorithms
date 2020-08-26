#include<iostream>
#include<string>

using namespace std;

int main(){
    int T; cin>>T;
    for(int t=0; t<T; t++){
        bool arr[26]={false};
        string s;cin>>s;
        for(int i=0; i<s.length();i++){
            arr[s[i]-'A'] = true;
        }
        int sum = 0;
        for(int i=0; i<26; i++){
            if(arr[i]==false)
                sum+=(i+65);
        }
        cout<<sum<<endl;
    }

    return 0;
}