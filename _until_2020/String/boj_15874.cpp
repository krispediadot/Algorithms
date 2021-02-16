#include<iostream>
#include<string>

using namespace std;

int main(){
    int k, n; cin>>k>>n; cin.ignore();
    string s; getline(cin, s);
    string ans = "";
    for(int i=0; i<n; i++){
        // 온점, 쉼표.
        if(s[i]=='.' || s[i]==',' || s[i]==' ')
            ans += s[i];
        // 대문자
        else if(s[i]>='A' && s[i]<='Z'){
            int index = (s[i]-'A'+k)%26;
            ans += char('A'+index);
        }
        // 소문자
        else if(s[i]>='a' && s[i]<='z'){
            int index = (s[i]-'a'+k)%26;
            ans += char('a'+index);
        }
    }
    cout<<ans<<endl;

    return 0;
}