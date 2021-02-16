#include<string>
#include<iostream>
#include<vector>

using namespace std;

struct Node{
    char c;
    string num;
    Node(char c, string num):c(c), num(num){}
};

vector<Node*> a;

char findChar(string s) {
    for (int i = 0; i < 8; i++){
        if (s.compare(a[i]->num) == 0)
            return a[i]->c;
        int gap = 0;
        for(int index=0; index<6; index++){
            //cout<<s[index]<<","<<a[i]->num[index]<<endl;
            if(s[index]==a[i]->num[index])
                continue;
            gap++;
            if(gap>1)
                break;
        }
        if(gap==1)
            return a[i]->c;
    }
    return NULL;
}
int main(){
    a.push_back(new Node('A',"000000"));
    a.push_back(new Node('B',"001111"));
    a.push_back(new Node('C',"010011"));
    a.push_back(new Node('D',"011100"));
    a.push_back(new Node('E',"100110"));
    a.push_back(new Node('F',"101001"));
    a.push_back(new Node('G',"110101"));
    a.push_back(new Node('H',"111010"));

    int n;cin>>n;
    string s;cin>>s;
    string ans = "";
    bool isNull=false;

    for(int i=0; i<n; i++){
        if(findChar(s.substr(6*i, 6))==NULL) {
            cout << i + 1;
            isNull = true;
            break;
        }
        ans += findChar(s.substr(6*i, 6));
    }
    if(!isNull)
        cout<<ans<<endl;

    return 0;
}