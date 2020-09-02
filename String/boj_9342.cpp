#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main(){
    int T;cin>>T;
    regex re("[ABCDEF]{0,1}A+F+C+[ABCDEF]{0,1}");
    for(int t=0; t<T; t++){
        string s;cin>>s;
        if(regex_match(s,re))
            cout<<"Infected!"<<endl;
        else
            cout<<"Good"<<endl;
    }

    return 0;
}
