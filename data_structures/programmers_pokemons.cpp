/*

-- unordered_map --

테스트 1 〉	통과 (0.01ms, 4.16MB)
테스트 2 〉	통과 (0.01ms, 4.15MB)
테스트 3 〉	통과 (0.01ms, 4.18MB)
테스트 4 〉	통과 (0.01ms, 4.18MB)
테스트 5 〉	통과 (0.01ms, 3.63MB)
테스트 6 〉	통과 (0.01ms, 4.18MB)
테스트 7 〉	통과 (0.02ms, 4.17MB)
테스트 8 〉	통과 (0.02ms, 4.17MB)
테스트 9 〉	통과 (0.02ms, 3.59MB)
테스트 10 〉	통과 (0.01ms, 3.58MB)
테스트 11 〉	통과 (0.01ms, 4.12MB)
테스트 12 〉	통과 (0.13ms, 3.76MB)
테스트 13 〉	통과 (0.08ms, 4.09MB)
테스트 14 〉	통과 (0.07ms, 4.1MB)
테스트 15 〉	통과 (0.05ms, 3.68MB)
테스트 16 〉	통과 (0.67ms, 4.1MB)
테스트 17 〉	통과 (0.68ms, 4.18MB)
테스트 18 〉	통과 (0.45ms, 4.11MB)
테스트 19 〉	통과 (0.28ms, 4.11MB)
테스트 20 〉	통과 (0.18ms, 4.26MB)
*/

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    unordered_map<int, int> pokemons;
    for (auto n : nums) pokemons[n]++;

    int limit = nums.size()/2;

    if (pokemons.size() > limit) answer = limit;
    else answer = pokemons.size();
    
    return answer;
}


/*

-- unordered_map w/ min --

테스트 1 〉	통과 (0.01ms, 4.13MB)
테스트 2 〉	통과 (0.01ms, 4.19MB)
테스트 3 〉	통과 (0.01ms, 4.25MB)
테스트 4 〉	통과 (0.01ms, 4.18MB)
테스트 5 〉	통과 (0.02ms, 3.84MB)
테스트 6 〉	통과 (0.01ms, 4.17MB)
테스트 7 〉	통과 (0.02ms, 4.18MB)
테스트 8 〉	통과 (0.02ms, 4.19MB)
테스트 9 〉	통과 (0.01ms, 3.59MB)
테스트 10 〉	통과 (0.01ms, 3.66MB)
테스트 11 〉	통과 (0.01ms, 3.58MB)
테스트 12 〉	통과 (0.15ms, 4.03MB)
테스트 13 〉	통과 (0.11ms, 3.72MB)
테스트 14 〉	통과 (0.08ms, 4.18MB)
테스트 15 〉	통과 (0.04ms, 3.61MB)
테스트 16 〉	통과 (0.97ms, 4.16MB)
테스트 17 〉	통과 (0.72ms, 4.08MB)
테스트 18 〉	통과 (0.48ms, 4.17MB)
테스트 19 〉	통과 (0.30ms, 4.18MB)
테스트 20 〉	통과 (0.18ms, 4.18MB)
*/

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums) {
    unordered_map<int, int> pokemons;
    for (auto n : nums) pokemons[n]++;
    
    return min(nums.size()/2, pokemons.size());
}
