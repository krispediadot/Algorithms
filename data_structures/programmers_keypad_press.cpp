/*
테스트 1 〉	통과 (0.01ms, 4.25MB)
테스트 2 〉	통과 (0.02ms, 4.12MB)
테스트 3 〉	통과 (0.01ms, 4.1MB)
테스트 4 〉	통과 (0.01ms, 4.17MB)
테스트 5 〉	통과 (0.04ms, 4.17MB)
테스트 6 〉	통과 (0.01ms, 4.18MB)
테스트 7 〉	통과 (0.02ms, 4.18MB)
테스트 8 〉	통과 (0.02ms, 3.58MB)
테스트 9 〉	통과 (0.02ms, 4.17MB)
테스트 10 〉	통과 (0.02ms, 4.11MB)
테스트 11 〉	통과 (0.02ms, 4.17MB)
테스트 12 〉	통과 (0.02ms, 4.18MB)
테스트 13 〉	통과 (0.02ms, 4.09MB)
테스트 14 〉	통과 (0.02ms, 4.17MB)
테스트 15 〉	통과 (0.04ms, 4.11MB)
테스트 16 〉	통과 (0.06ms, 3.68MB)
테스트 17 〉	통과 (0.07ms, 4.11MB)
테스트 18 〉	통과 (0.06ms, 4.16MB)
테스트 19 〉	통과 (0.07ms, 4.18MB)
테스트 20 〉	통과 (0.06ms, 3.63MB)
*/

#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    unordered_map<int, string> mapping = {{1, "L"},
                                           {4, "L"},
                                           {7, "L"},
                                           {3, "R"},
                                           {6, "R"},
                                           {9, "R"}};
    
    vector<pair<int, int>> location = {{3, 1},
                                        {0, 0},
                                        {0, 1},
                                        {0, 2},
                                        {1, 0},
                                        {1, 1},
                                        {1, 2},
                                        {2, 0},
                                        {2, 1},
                                        {2, 2},
                                        {3, 0},
                                        {3, 2}};
    
    pair<int, int>* left = &location[10];
    pair<int, int>* right = &location[11];
    
    for (auto n : numbers) {
        string result = "";
        
        if (mapping[n] != "") result = mapping[n];
        else {
            int distL = abs(location[n].first - left->first) + abs(location[n].second - left->second);
            int distR = abs(location[n].first - right->first) + abs(location[n].second - right->second);
            
            if (distL < distR) result = "L";
            else if (distL > distR) result = "R";
            else {
                if (hand == "left") result = "L";
                else result = "R";
            }
        }
        
        if (result == "L") left = &location[n];
        else right = &location[n];
        
        answer += result;
    }
     
    return answer;
}
