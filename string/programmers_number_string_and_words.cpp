/*

-- unordered_map 사용 --

테스트 1 〉	통과 (0.01ms, 4.09MB)
테스트 2 〉	통과 (0.01ms, 4.1MB)
테스트 3 〉	통과 (0.01ms, 4.05MB)
테스트 4 〉	통과 (0.01ms, 4.17MB)
테스트 5 〉	통과 (0.01ms, 4.01MB)
테스트 6 〉	통과 (0.01ms, 3.69MB)
테스트 7 〉	통과 (0.01ms, 4.03MB)
테스트 8 〉	통과 (0.01ms, 3.59MB)
테스트 9 〉	통과 (0.01ms, 3.6MB)
테스트 10 〉	통과 (0.02ms, 4.08MB)
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dict = {{"zero", 0},
                                   {"one", 1},
                                   {"two", 2},
                                   {"three", 3},
                                   {"four", 4},
                                   {"five", 5},
                                   {"six", 6},
                                   {"seven", 7},
                                   {"eight", 8},
                                   {"nine", 9}
                                  };

int solution(string s) {
    int answer = 0;
    
    int idx = 0;
    while (idx < s.length()) {
        if (isdigit(s[idx])) {
            answer *= 10;
            answer += (s[idx] - '0');
        }
        else {
            int endIdx = idx;
            while (endIdx < s.length() && isdigit(s[endIdx]) == false) {
                endIdx++;   
            }
            
            int len = 3;
            while (idx < endIdx) {
                if (s.substr(idx, len) == "zero" || dict[s.substr(idx, len)] != 0) {
                    answer *= 10;
                    answer += (dict[s.substr(idx, len)]);
                    idx += len;
                    len = 3;
                }
                else len++;
            }
            
            idx = endIdx - 1;
        }
        
        idx++;
    }
    
    return answer;
}

/*

-- regex 사용 --

테스트 1 〉	통과 (0.04ms, 4.18MB)
테스트 2 〉	통과 (0.04ms, 4.18MB)
테스트 3 〉	통과 (0.04ms, 4.18MB)
테스트 4 〉	통과 (0.04ms, 4.25MB)
테스트 5 〉	통과 (0.05ms, 4.18MB)
테스트 6 〉	통과 (0.06ms, 4.18MB)
테스트 7 〉	통과 (0.05ms, 4.2MB)
테스트 8 〉	통과 (0.07ms, 4.18MB)
테스트 9 〉	통과 (0.05ms, 4.18MB)
테스트 10 〉	통과 (0.04ms, 3.88MB)
*/

#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < numbers.size(); i++) {
        s = regex_replace(s, regex(numbers[i]), to_string(i));
    }
    
    answer = stoi(s);
    
    return answer;
}
