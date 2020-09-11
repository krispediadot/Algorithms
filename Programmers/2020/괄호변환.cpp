#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> split(string s){
    int in=0; int index;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') in++;
        if(in*2 == i+1) {
            index = i;
            break;
        }
    }
    vector<string> res;
    res.push_back(s.substr(0,index+1));
    res.push_back(s.substr(index+1));
    return res;
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
string convert(string target){
    string answer = "";

    if(target.length()==0)
        return target;

    // u,v 나누기
    vector<string> sp = split(target);
    string u = sp[0];
    string v = sp[1];
    // u 올바른 괄호인지 확인
    // 올바르다면
    if(isCorrect(u)) {
        // 1. 결과에 붙이고 v 손보기
        answer += u;
        answer += convert(v);
    }
        // 올바르지 않다면
    else {
        // 1. 결과에 ( 붙이고
        answer += '(';
        // 2. 옿바르게 정렬한 v 붙이고
        answer += convert(v);
        // 3. ) 붙이고
        answer += ')';
        // 4. u 앞 뒤 제거
        // 5. u 괄호 뒤집어서 붙이기
        for(int i=1; i<u.length()-1; i++){
            if(u[i]==')') answer+='(';
            else answer+=')';
        }
    }
    return answer;
}
string solution(string p){
    return convert(p);
}

int main(){
    string p; cin>>p;
    cout<<solution(p);
}
