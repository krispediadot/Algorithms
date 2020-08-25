#include<iostream>
#include<string>

using namespace std;

int maxLen(string s){
    int a[8]={0};
    for(int i=1; i<s.length(); i++){
        if(s[i-1]==s[i])
            a[i] = a[i-1]+1;
    }
    int max = 0;
    for(int i=0; i<8; i++){
        if(a[i]>max)
            max = a[i];
    }
    return max;
}

int main(){

    string s[3];
    cin >> s[0];
    cin >> s[1];
    cin >> s[2];

    for(int i=0; i<3; i++)
        cout<<maxLen(s[i])+1<<endl;

    return 0;
}