#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main(){
    regex re("nemo", regex::icase);
    string s;
    while(true){
        getline(cin,s);
        if(s.compare("EOI")==0)
            break;
        if(regex_search(s,re))
            cout<<"Found"<<endl;
        else
            cout<<"Missing"<<endl;
    }

    return 0;
}