#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets = {{')','('},
                                              {'}','{'},
                                              {']','['}};
        
        stack<char> st;
        
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (!st.empty() && st.top() == brackets[c]) st.pop();
                else return false;
            }
        }
        
        if (st.empty()) return true;
        return false;
    }
};

int main() {
    Solution solution;
    cout << boolalpha << solution.isValid("[]") << endl;  // true
    cout << boolalpha << solution.isValid("[]{}") << endl; // true
    cout << boolalpha << solution.isValid("[]{)") << endl; // false
    cout << boolalpha << solution.isValid("]{)") << endl; // false
}
