#include<iostream>
#include<string>

using namespace std;

int main(){
    string a,b;
    char c;
    cin>>a>>c>>b;

    if(c=='*') {
        cout << 1;
        for(int i=0; i<(a.length()-1)+(b.length()-1); i++)
            cout<<0;
    }
    else if(c=='+') {
        int len = a.length() > b.length() ? a.length() : b.length();
        int t = a.length() < b.length() ? a.length() : b.length();
        if(len!=t) {
            cout << 1;
            for (int i = 1; i < len; i++) {
                if (i == len - t)
                    cout << 1;
                else
                    cout << 0;
            }
        }
        else{
            cout<<2;
            for(int i=1; i<len; i++){
                cout<<0;
            }
        }
    }
    return 0;
}

