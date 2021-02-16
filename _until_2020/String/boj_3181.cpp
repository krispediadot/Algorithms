#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

vector<string> ig;

int main(){
    ig.push_back("i");
    ig.push_back("pa");
    ig.push_back("te");
    ig.push_back("ni");
    ig.push_back("niti");
    ig.push_back("a");
    ig.push_back("ali");
    ig.push_back("nego");
    ig.push_back("no");
    ig.push_back("ili");

    string s; getline(cin,s);
    stringstream ss(s);
    string tmp;
    vector<string> sub;
    while(getline(ss,tmp,' ')){
        sub.push_back(tmp);
    }

    tmp = "";
    for(int i=0; i<sub.size(); i++){
        if(i!=0 && find(ig.begin(), ig.end(), sub[i])!=ig.end())
            continue;
        tmp += char(sub[i][0]-('a'-'A'));
    }
    cout<<tmp<<endl;

    return 0;
}