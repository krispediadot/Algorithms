/*

-- no memoization -- 

테스트 1 〉	통과 (0.17ms, 4.11MB)
테스트 2 〉	통과 (0.19ms, 3.71MB)
테스트 3 〉	통과 (0.06ms, 3.54MB)
테스트 4 〉	통과 (0.03ms, 4.17MB)
테스트 5 〉	통과 (0.28ms, 4.11MB)
테스트 6 〉	통과 (1.53ms, 4.19MB)
테스트 7 〉	통과 (0.05ms, 3.56MB)
테스트 8 〉	통과 (2.25ms, 4.2MB)
테스트 9 〉	통과 (0.23ms, 4.18MB)
테스트 10 〉	통과 (2.77ms, 3.59MB)
테스트 11 〉	통과 (0.01ms, 4.12MB)
테스트 12 〉	통과 (0.01ms, 4.16MB)
테스트 13 〉	통과 (0.01ms, 3.58MB)
테스트 14 〉	통과 (0.03ms, 3.6MB)
테스트 15 〉	통과 (0.02ms, 4.11MB)
테스트 16 〉	통과 (6.52ms, 4.2MB)
테스트 17 〉	통과 (0.06ms, 4.11MB)
테스트 18 〉	통과 (0.09ms, 4.17MB)
테스트 19 〉	통과 (0.02ms, 4.18MB)
테스트 20 〉	통과 (10.75ms, 4.18MB)
테스트 21 〉	통과 (9.46ms, 4.17MB)
테스트 22 〉	통과 (0.02ms, 4.17MB)
테스트 23 〉	통과 (0.01ms, 4.11MB)
테스트 24 〉	통과 (8.94ms, 4.12MB)
테스트 25 〉	통과 (8.22ms, 4.1MB)
테스트 26 〉	통과 (0.01ms, 4.16MB)
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int number) {
    for (int i = 2; i < number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    
    sort(nums.begin(), nums.end());
    
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i+1; j < nums.size() - 1; j++) {
            for (int k = j+1; k < nums.size(); k++) {
                int number = nums[i] + nums[j] + nums[k];
                
                if (isPrime(number)) answer++;
            }
        }
    }

    return answer;
}

/*

-- unordered_set memoization --

테스트 1 〉	통과 (0.10ms, 4.2MB)
테스트 2 〉	통과 (0.12ms, 4.21MB)
테스트 3 〉	통과 (0.04ms, 4.18MB)
테스트 4 〉	통과 (0.04ms, 3.57MB)
테스트 5 〉	통과 (0.13ms, 4.19MB)
테스트 6 〉	통과 (0.39ms, 4.19MB)
테스트 7 〉	통과 (0.04ms, 4.17MB)
테스트 8 〉	통과 (0.64ms, 3.58MB)
테스트 9 〉	통과 (0.14ms, 4.18MB)
테스트 10 〉	통과 (0.64ms, 3.67MB)
테스트 11 〉	통과 (0.02ms, 4.18MB)
테스트 12 〉	통과 (0.01ms, 4.17MB)
테스트 13 〉	통과 (0.02ms, 4.18MB)
테스트 14 〉	통과 (0.01ms, 3.66MB)
테스트 15 〉	통과 (0.01ms, 4.04MB)
테스트 16 〉	통과 (1.73ms, 4.14MB)
테스트 17 〉	통과 (0.20ms, 3.71MB)
테스트 18 〉	통과 (0.09ms, 3.49MB)
테스트 19 〉	통과 (0.02ms, 4.18MB)
테스트 20 〉	통과 (2.05ms, 4.17MB)
테스트 21 〉	통과 (2.21ms, 4.2MB)
테스트 22 〉	통과 (0.06ms, 4.17MB)
테스트 23 〉	통과 (0.01ms, 4.17MB)
테스트 24 〉	통과 (1.56ms, 4.11MB)
테스트 25 〉	통과 (2.07ms, 4.18MB)
테스트 26 〉	통과 (0.01ms, 4.11MB)
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isPrime(int number) {
    for (int i = 2; i < number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    
    unordered_set<int> prime;
    
    sort(nums.begin(), nums.end());
    
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i+1; j < nums.size() - 1; j++) {
            for (int k = j+1; k < nums.size(); k++) {
                int number = nums[i] + nums[j] + nums[k];
                
                if (prime.find(number) != prime.end() || isPrime(number)) {
                    prime.insert(number);
                    answer++;
                }
            }
        }
    }

    return answer;
}
