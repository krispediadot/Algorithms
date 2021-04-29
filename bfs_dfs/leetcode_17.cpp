// 0ms, 6.7MB, 43:24
class Solution {
    unordered_map<char, string> m = {{'2', "abc"},
                                     {'3', "def"},
                                     {'4', "ghi"},
                                     {'5', "jkl"},
                                     {'6', "mno"},
                                     {'7', "pqrs"},
                                     {'8', "tuv"},
                                     {'9', "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;

        if (digits.length() == 0) return answer;
        if (digits.length() == 1) {
            for (auto target : m[digits[0]]) {
                answer.push_back(string(1, target));
            }
        }
        else {
            vector<string> temp = letterCombinations(digits.substr(1));
        
            for (auto target : m[digits[0]]) {
                for (auto t : temp) {
                    answer.push_back(target + t);
                }
            }
        }

        return answer;
    }
};
