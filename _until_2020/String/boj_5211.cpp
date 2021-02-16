#include<iostream>
#include<string>

using namespace std;

int main(){
    string s; cin>>s;

    int A=0;
    int C=0;

    for(int i=0; i<s.length(); i++){
        if(i==0||s[i-1]=='|'){
            if(s[i]=='A' || s[i]=='D' || s[i]=='E')
                A++;
            if(s[i]=='C' || s[i]=='F' || s[i]=='G')
                C++;
        }
    }
    if(A==C){
        A+=(s[s.length()-1]=='A');
        A+=(s[s.length()-1]=='D');
        A+=(s[s.length()-1]=='E');
        C+=(s[s.length()-1]=='C');
        C+=(s[s.length()-1]=='F');
        C+=(s[s.length()-1]=='G');
    }
    if(A>C)
        cout<<"A-minor"<<endl;
    else
        cout<<"C-major"<<endl;

    return 0;
}