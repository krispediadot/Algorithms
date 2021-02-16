#include<iostream>
#include<string>

using namespace std;

int main(){
    string s; cin>>s;
    bool yujin = false;

    for(int i=1; i<s.length(); i++){
        string s1 = s.substr(0,i);
        string s2 = s.substr(i);

        int r1=1, r2=1;
        for(int i=0; i<s1.length(); i++)
            r1*=s1[i]-'0';
        for(int i=0; i<s2.length(); i++)
            r2*=s2[i]-'0';
        //cout<<r1<<" "<<r2<<endl;
        if(r1==r2){
            yujin=true;
            break;
        }
    }
    if(yujin) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}