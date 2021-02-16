#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main(){
    regex re(".*problem.*", regex::icase);

    while(true){
        string s; getline(cin,s);
        if(cin.eof())
            break;

        if(regex_search(s,re))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}