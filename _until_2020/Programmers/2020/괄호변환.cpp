#include<iostream>
#include<string>
#include<vector>

using namespace std;

int splitIndex(string s){
    int in=0; int index;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') in++;
        if(in*2 == i+1) {
            index = i;
            return index;
        }
    }
}
bool isCorrect(string s){
    int in=0;
    if(s.length()==0)
        return true;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') in++;
        else in--;
        if(in<0) return false;
    }
    return true;
}
string solution(string target){
    string answer = "";

    if(target.length()==0)
        return target;

    // u,v 나누기
    int index = splitIndex(target);
    string u = target.substr(0, index+1);
    string v = target.substr(index+1);
    // u 올바른 괄호인지 확인
    // 올바르다면
    // 1. 결과에 붙이고 v 손보기
    if(isCorrect(u)) return u + solution(v);
    // 올바르지 않다면
    // 1. ( 붙이고 2. v 손보고 3. ) 붙이고 4.u 1~size-1까지 괄호 바꿔서 출력
    for(char &c: u) c = c=='('?')':'(';
    return '('+solution(v)+')'+u.substr(1,u.length()-2);
}

int main(){
    string p; cin>>p;
    cout<<solution(p);
}