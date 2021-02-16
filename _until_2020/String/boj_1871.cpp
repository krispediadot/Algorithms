#include<iostream>
#include<string>

using namespace std;

int main(){
    int T; cin>>T;
    for(int t=0; t<T; t++){
        string s; cin>>s;
        int multi = 26*26;
        int a = 0;

        for(int i=0; i<3; i++){
            a += (int(s[i])-'A')*multi;
            multi /= 26;
        }
        int b = stoi(s.substr(4,4));
        //cout<<a<<", "<<b<<endl;
        if(-100<=a-b && a-b<=100) {
            cout << "nice" << endl;
        }
        else
            cout<<"not nice"<<endl;
    }

    return 0;
}