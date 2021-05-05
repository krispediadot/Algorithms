#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long calc(long long& a, long long& b, char& op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> numbers;
    vector<char> operators;
    vector<char> operators_priority;
    
    long long n = 0;
    
    // 1. split expression by operator
    for (auto e : expression) {
        if (e == '+' || e == '-' || e == '*') {
            numbers.push_back(n);
            n = 0;
            operators.push_back(e);
            if (find(operators_priority.begin(), operators_priority.end(), e) == operators_priority.end())
                operators_priority.push_back(e);
        }
        else {
            n *= 10;
            n += (e - '0');
        }
    }
    numbers.push_back(n);
    
    sort(operators_priority.begin(), operators_priority.end());
    
    // 2. calculate expression ordered by operator priority
    do {

        vector<long long> numbers_copy = numbers;
        vector<char> operators_copy = operators;

        for (auto target_op : operators_priority) {
            for (int i = 0; i < operators_copy.size(); i++) {
                if (operators_copy[i] == target_op) {
                    
                    numbers_copy[i] = calc(numbers_copy[i], numbers_copy[i + 1], target_op);
                    numbers_copy.erase(numbers_copy.begin() + i + 1);

                    operators_copy.erase(operators_copy.begin() + i);

                    i--;
                }
            }
        }

        answer = max(answer, abs(numbers_copy[0]));
        
    } while (next_permutation(operators_priority.begin(), operators_priority.end()));
    
    return answer;
}
