#include<string>
#include<iostream>
#include<regex>

using namespace std;

int main(){
    while(true){
        bool c[26]={false,};
        string s;getline(cin,s);
        if(s=="#")
            break;

        regex re("[a-zA-Z]");
        int count=0;
        for(int i=0; i<s.length(); i++){
            if(regex_match(s.substr(i,1),re)) {
                int index = s[i] >= 'a' ? (s[i] - 'a') : (s[i] - 'A');
                if (c[index] == false) {
                    count++;
                    c[index] = true;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}