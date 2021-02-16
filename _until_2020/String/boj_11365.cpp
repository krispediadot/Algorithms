#include<iostream>
#include<string>

using namespace std;

int main(){
    while(1){
        string s; getline(cin, s);
        if(s.compare("END")==0)
            break;
        string ans = "";
        for(int i=s.length()-1; i>=0; i--){
            ans+=s[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}