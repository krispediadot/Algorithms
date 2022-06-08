/*
정확성  테스트
테스트 1 〉	통과 (0.01ms, 4.19MB)
테스트 2 〉	통과 (0.01ms, 4.18MB)
테스트 3 〉	통과 (0.20ms, 3.79MB)
테스트 4 〉	통과 (0.36ms, 4.05MB)
테스트 5 〉	통과 (0.37ms, 4.18MB)
효율성  테스트
테스트 1 〉	통과 (22.60ms, 17.9MB)
테스트 2 〉	통과 (35.62ms, 25.4MB)
테스트 3 〉	통과 (43.91ms, 30MB)
테스트 4 〉	통과 (48.75ms, 32.5MB)
테스트 5 〉	통과 (47.20ms, 32.5MB)
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> people;
    for (auto p : participant) people[p]++;
    
    for (auto c : completion) {
        people[c]--;
        if (people[c] == 0) people.erase(c);
    }
    
    answer = people.begin()->first;
    
    return answer;
}
