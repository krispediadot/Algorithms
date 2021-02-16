#include<string>
#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> stack;
    string s;getline(cin,s);
    string ans = "";

    while(s.length()>0){
        if(stack.empty()) {
            if (s.substr(0, 2).compare("<<")==0) {
                stack.push(1);
                s = s.substr(2);
                ans += "[";
                continue;
            }
            if(s.substr(0,2).compare(">>")==0) {
                stack.push(-1);
                s = s.substr(2);
                ans += "[";
                continue;
            }
            s = s.substr(1);
        }
        else{
            int top = stack.top();
            int cur = 2;
            if(s.substr(0,2).compare("<<")==0)
                cur = 1;
            if(s.substr(0,2).compare(">>")==0)
                cur = -1;
            if(top+cur==0) {
                stack.pop();
                s = s.substr(2);
                ans += "]";
                continue;
            }
            if(cur==1 || cur==-1) {
                stack.push(cur);
                s = s.substr(2);
                ans += "[";
            }
            else
                s = s.substr(1);
        }
    }
    if(stack.empty())
        cout<<ans<<endl;
    else
        cout<<"Keine Loesung"<<endl;

    return 0;
}