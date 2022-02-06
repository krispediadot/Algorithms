/*
테스트 1 〉	통과 (0.02ms, 4.32MB)
테스트 2 〉	통과 (0.03ms, 4.32MB)
테스트 3 〉	통과 (413.88ms, 27.3MB)
테스트 4 〉	통과 (0.05ms, 3.67MB)
테스트 5 〉	통과 (0.04ms, 4.33MB)
테스트 6 〉	통과 (0.96ms, 4.26MB)
테스트 7 〉	통과 (2.61ms, 4.33MB)
테스트 8 〉	통과 (4.99ms, 4.21MB)
테스트 9 〉	통과 (102.00ms, 15.2MB)
테스트 10 〉	통과 (99.74ms, 15MB)
테스트 11 〉	통과 (390.20ms, 27MB)
테스트 12 〉	통과 (0.23ms, 3.83MB)
테스트 13 〉	통과 (0.25ms, 4.34MB)
테스트 14 〉	통과 (224.93ms, 15.1MB)
테스트 15 〉	통과 (376.19ms, 26.7MB)
테스트 16 〉	통과 (0.26ms, 4.26MB)
테스트 17 〉	통과 (0.42ms, 3.71MB)
테스트 18 〉	통과 (0.44ms, 3.81MB)
테스트 19 〉	통과 (0.72ms, 4.32MB)
테스트 20 〉	통과 (182.43ms, 15.1MB)
테스트 21 〉	통과 (363.54ms, 26.5MB)
테스트 22 〉	통과 (0.02ms, 3.69MB)
테스트 23 〉	통과 (0.02ms, 4.2MB)
테스트 24 〉	통과 (0.02ms, 3.69MB)
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    vector<vector<int>> cnts(id_list.size(), vector<int>());
    
    for (auto& r : report) {
        istringstream is(r);
        string id, pick; is >> id >> pick;
        
        int id_idx = find(id_list.begin(), id_list.end(), id) - id_list.begin();
        int pick_idx = find(id_list.begin(), id_list.end(), pick) - id_list.begin();
        
        if (find(cnts[pick_idx].begin(), cnts[pick_idx].end(), id_idx) == cnts[pick_idx].end())
            cnts[pick_idx].push_back(id_idx);
    }
    
    for (auto& cnt : cnts) {
        if (cnt.size() >= k) {
            for (auto& c : cnt) answer[c]++;
        }
    }
    
    return answer;
}
