#include<iostream>
#include<string>

using namespace std;

int main(){
    int t; cin>>t; cin.ignore();
    for(int tt=1; tt<=t; tt++){
        string s; getline(cin, s);
        string ans = "";

        for(int i=0; i<s.length(); i++){
            if(s[i]==' ') {
                if(ans.length()!=0 && ans.substr(ans.length()-1).compare("0")==0)
                    ans += ' ';
                ans += '0';
                continue;
            }
            int push, times;
            int index = s[i] - 'a';

            if (index == 18) {
                push = 7;
                times = 3;
            } else if (index == 25) {
                push = 9;
                times = 3;
            }
            else {
                if (index > 18)
                    index -= 1;

                push = index / 3 + 2;
                times = index % 3;
            }

            if(ans.length()!=0 && ans.substr(ans.length()-1).compare(to_string(push))==0)
                ans += ' ';

            for(int time=0; time<times+1; time++)
                ans += to_string(push);
        }

        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }


}