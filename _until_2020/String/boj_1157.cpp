#include<iostream>
#include<string>

using namespace std;

int main(){
    int c[26]= {0,};
    string s; cin>>s;

    for(int i=0; i<s.length(); i++){
        if(s[i]>='A' && s[i]<='Z') c[s[i]-'A']++;
        else if(s[i]>='a' && s[i]<='z') c[s[i]-'a']++;
    }
    bool multi = false;
    int maxIndex = 0;

    for(int i=1; i<26; i++){
        if(c[i]>c[maxIndex]){
            multi = false;
            maxIndex = i;
        }
        else if(c[i]==c[maxIndex])
            multi = true;
    }
    if(multi) cout<<"?"<<endl;
    else cout<<char(maxIndex+'A')<<endl;

    return 0;
}