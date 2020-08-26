#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;cin>>s;
    string answer="";

    answer+=s[0];
    while(s.find('-')!=string::npos){
        int index = s.find('-');
        answer+=s[index+1];
        s = s.substr(index+1);
    }
    cout<<answer<<endl;

    return 0;
}