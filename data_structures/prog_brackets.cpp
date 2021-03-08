#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

bool solution(string s) {
    bool answer = true;
    unordered_map<char, char> brackets{
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    stack<char> st;
    
    for (auto& c : s) {
        if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || st.top() != brackets[c]) {
                answer = false;
                break;
            }
            st.pop();
        }
        else st.push(c);
    }
    
    if (!st.empty()) answer = false;
    return answer;
}

int main() {
    cout << solution("{{}}") << endl; // true
    cout << solution("({})[]") << endl; // true
    cout << solution("[)") << endl; // false
    cout << solution("]()[") << endl; // false
    cout << solution("([())]") << endl; // false
}

