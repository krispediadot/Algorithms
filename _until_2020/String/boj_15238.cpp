#include<iostream>
#include<string>

using namespace std;

int main(){
    int c[26] = {0,};
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0; i<s.length(); i++){
        c[s[i]-'a']++;
    }
    int index = 0;
    int max = c[0];

    for(int i=0; i<26; i++){
        if(c[i]>max){
            max = c[i];
            index = i;
        }
    }
    cout<<char(index+'a')<<" "<<max<<endl;

    return 0;
}