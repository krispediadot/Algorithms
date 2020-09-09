#include<iostream>
#include<string>
#include<regex>
#include<sstream>
#include<vector>

using namespace std;

void solution(string s){
    // string -> tautogram 확인
    // 각 단어의 첫글자가 같은지 확인

    char target = isupper(s[0])?s[0]:s[0]-('a'-'A');
    string ex = "[].*";
    ex.insert(1,1,target);
    ex.insert(1,1,char(target+('a'-'A')));
    regex re(ex);

    vector<string> split;
    stringstream ss(s);
    string tmp;
    while(getline(ss, tmp, ' ')){
        split.push_back(tmp);
    }
    bool ok = true;
    for(int i=0; i<split.size(); i++){
        if(regex_match(split[i], re) == false){
            ok = false;
            break;
        }
    }
    if(ok) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
}
int main(){

    while(1){
        string s; getline(cin, s);
        if(s=="*")
            break;
        solution(s);
    }

    return 0;
}