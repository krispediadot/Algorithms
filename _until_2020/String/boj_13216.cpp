#include<iostream>
#include<string>

using namespace std;

int main(){
    string s; cin>>s;

    int a=0, b=0, aC=0, bC=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='A')
            a++;
        if(s[i]=='B')
            b++;

        if(a==21||b==21) {
            cout<<a<<"-"<<b<<endl;
            if(a==21) aC++;
            else bC++;
            a=0;
            b=0;
        }
        if(aC==2){
            cout<<"A"<<endl;
            break;
        }
        if(bC==2){
            cout<<"B"<<endl;
            break;
        }
    }

    return 0;
}