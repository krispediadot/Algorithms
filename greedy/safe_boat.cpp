#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end(), greater<int>());
    
    int answer = 0;
    int idx = 0;
    int last_idx = people.size() - 1;
    
    while (idx <= last_idx) {
        int left_limit = limit - people[idx];
        if (left_limit >= people[last_idx])
            last_idx--;
        answer++;

        idx++;
    }
    
    return answer;
}

int main() {
    cout << solution({70, 50, 80, 50}, 100) << endl; // 3
}
