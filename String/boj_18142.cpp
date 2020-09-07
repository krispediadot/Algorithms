#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){
    string s; getline(cin, s);
    stringstream ss(s);
    string tmp;
    vector<string> split;
    while(getline(ss,tmp,' ')){
        split.push_back(tmp);
    }
    tmp = "";
    for(int i=0; i<split.size(); i++){
        if(split[i].compare("tapioka")==0 || split[i].compare("bubble")==0)
            continue;
        tmp += split[i];
        if(i<split.size()-1)
            tmp += ' ';
    }
    if(tmp=="")
        cout<<"nothing"<<endl;
    else
        cout<<tmp<<endl;


    return 0;
}