#include<iostream>
#include<string>
#include<cmath>
 
using namespace std;
 
int res=0;
int a,b;
 
bool checkPalindrome(string s, int mode){
    string d = to_string(int(sqrt(stoi(s))));
    int ps=0, pe=s.length()-1;
    while(ps<pe){
        if(s[ps]!=s[pe])
            return false;
        ps++;
        pe--;
    }
    if(mode==0 &&stoi(d)*stoi(d)==stoi(s) && checkPalindrome(d,1)) {
        res++;
        return true;
    }
    if(mode==1)
        return true;
    return false;
}
int main(){
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        res=0;
        cin>>a>>b;
        for(int i=a; i<=b; i++)
            checkPalindrome(to_string(i),0);
        cout<<"#"<<t<<" "<<res<<endl;
    }
    return 0;
}
