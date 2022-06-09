/*

-- simple compare --

테스트 1 〉	통과 (0.01ms, 4.1MB)
테스트 2 〉	통과 (0.01ms, 4.15MB)
테스트 3 〉	통과 (0.01ms, 4.11MB)
테스트 4 〉	통과 (0.01ms, 4.17MB)
테스트 5 〉	통과 (0.01ms, 4.17MB)
테스트 6 〉	통과 (0.01ms, 4.1MB)
테스트 7 〉	통과 (0.03ms, 4.18MB)
테스트 8 〉	통과 (0.01ms, 4.09MB)
테스트 9 〉	통과 (0.06ms, 4.11MB)
테스트 10 〉	통과 (0.03ms, 4.16MB)
테스트 11 〉	통과 (0.06ms, 4.17MB)
테스트 12 〉	통과 (0.05ms, 4.13MB)
테스트 13 〉	통과 (0.01ms, 3.59MB)
테스트 14 〉	통과 (0.05ms, 4.24MB)
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    string student1 = "12345";
    string student2 = "21232425";
    string student3 = "3311224455";
    
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        if (student1[i%student1.length()] - '0' == answers[i]) cnt1++;
        if (student2[i%student2.length()] - '0' == answers[i]) cnt2++;
        if (student3[i%student3.length()] - '0' == answers[i]) cnt3++;
    }

    if (cnt1 == cnt2 && cnt2 == cnt3) answer = {1,2,3};
    else {
        if (cnt1 >= cnt2) {
            if (cnt1 >= cnt3) answer.push_back(1);
            if (cnt3 >= cnt1) answer.push_back(3);
        }
        if (cnt2 >= cnt1) {
            if (cnt2 >= cnt3) answer.push_back(2);
            if (cnt3 >= cnt2) answer.push_back(3);
        }     
    }
    
    return answer;
}

/*

-- max_element --

테스트 1 〉	통과 (0.01ms, 4.18MB)
테스트 2 〉	통과 (0.01ms, 4.18MB)
테스트 3 〉	통과 (0.01ms, 4.23MB)
테스트 4 〉	통과 (0.01ms, 4.2MB)
테스트 5 〉	통과 (0.01ms, 4.1MB)
테스트 6 〉	통과 (0.01ms, 4.1MB)
테스트 7 〉	통과 (0.06ms, 4.16MB)
테스트 8 〉	통과 (0.02ms, 4.09MB)
테스트 9 〉	통과 (0.09ms, 4.07MB)
테스트 10 〉	통과 (0.05ms, 4.18MB)
테스트 11 〉	통과 (0.10ms, 4.09MB)
테스트 12 〉	통과 (0.09ms, 4.18MB)
테스트 13 〉	통과 (0.01ms, 4.17MB)
테스트 14 〉	통과 (0.04ms, 4.11MB)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3, 0);
    
    string student1 = "12345";
    string student2 = "21232425";
    string student3 = "3311224455";
    
    for (int i = 0; i < answers.size(); i++) {
        if (student1[i%student1.length()] - '0' == answers[i]) score[0]++;
        if (student2[i%student2.length()] - '0' == answers[i]) score[1]++;
        if (student3[i%student3.length()] - '0' == answers[i]) score[2]++;
    }

    int max_score = *max_element(score.begin(), score.end());
    
    for (int i = 0; i < 3; i++) {
        if (score[i] == max_score) answer.push_back(i+1);
    }
    
    return answer;
}
