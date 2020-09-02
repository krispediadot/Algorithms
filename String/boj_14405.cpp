#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;cin>>s;

    while(s.length()>0){
        //cout<<s<<endl;
        if(s.substr(0,2).compare("pi")==0) {
            s = s.substr(2);
            continue;
        }
        if(s.substr(0,2).compare("ka")==0){
            s = s.substr(2);
            continue;
        }
        if(s.substr(0,3).compare("chu")==0){
            s = s.substr(3);
            continue;
        }
        break;
    }
    if(s.length()==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
