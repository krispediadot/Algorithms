#include<iostream>
#include<string>

using namespace std;

int main(){
    char arr[5][16];
    int maxLen = 0;
    for(int i=0; i<5; i++) {
        string s; cin >> s;
        arr[i][0] = s.length();
        if(s.length()>maxLen) maxLen = s.length();
        for(int j=1; j<=s.length(); j++){
            arr[i][j] = s[j-1];
        }
    }
    for(int i=1; i<=maxLen; i++){
        for(int j=0; j<5; j++){
            if(arr[j][0]<i)
                continue;
            cout<<arr[j][i];
        }
    }
}