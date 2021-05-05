// 00:21:00
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDistance(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// 각 번호를 누른 손이 왼손인지 오른손인지 
string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pair<int, int> left = {3, 0};
    pair<int, int> right = {3, 2};
    
    for (auto target : numbers) {
        
        // 2. 
        if (target == 1 || target == 4 || target == 7) {
            answer += 'L';
            left = {target / 3, 0};
        }
        
        // 3. 
        else if (target == 3 || target == 6 || target == 9) {
            answer += 'R';
            right = {target / 3 - 1, 2};
        }
        
        // 4.
        else {
            pair<int, int> target_loc;
            if (target == 0) target_loc = {3, 1};
            else target_loc = {target / 3, 1};
            
            // 양 손과의 거리 구하기
            int dist_left = getDistance(left, target_loc);
            int dist_right = getDistance(right, target_loc);
            
            if (dist_left < dist_right) {
                answer += 'L';
                left = target_loc;
            }
            else if (dist_left > dist_right) {
                answer += 'R';
                right = target_loc;
            }
            // 거리 같다면 
            else {
                if (hand == "left") {
                    answer += 'L';
                    left = target_loc;
                }
                else {
                    answer += 'R';
                    right = target_loc;
                }
            }
        }
    }
    
    return answer;
}
