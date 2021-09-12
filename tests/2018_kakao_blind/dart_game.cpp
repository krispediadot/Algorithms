/*
테스트 1 〉	통과 (0.02ms, 3.68MB)
테스트 2 〉	통과 (0.02ms, 4.38MB)
테스트 3 〉	통과 (0.02ms, 4.2MB)
테스트 4 〉	통과 (0.02ms, 4.26MB)
테스트 5 〉	통과 (0.02ms, 3.77MB)
테스트 6 〉	통과 (0.02ms, 4.25MB)
테스트 7 〉	통과 (0.02ms, 4.28MB)
테스트 8 〉	통과 (0.02ms, 4.23MB)
테스트 9 〉	통과 (0.02ms, 4.26MB)
테스트 10 〉	통과 (0.02ms, 3.82MB)
테스트 11 〉	통과 (0.02ms, 3.77MB)
테스트 12 〉	통과 (0.02ms, 4.27MB)
테스트 13 〉	통과 (0.02ms, 4.33MB)
테스트 14 〉	통과 (0.02ms, 3.76MB)
테스트 15 〉	통과 (0.02ms, 4.25MB)
테스트 16 〉	통과 (0.02ms, 3.77MB)
테스트 17 〉	통과 (0.02ms, 4.25MB)
테스트 18 〉	통과 (0.02ms, 3.84MB)
테스트 19 〉	통과 (0.02ms, 4.21MB)
테스트 20 〉	통과 (0.02ms, 3.81MB)
테스트 21 〉	통과 (0.02ms, 3.86MB)
테스트 22 〉	통과 (0.02ms, 4.27MB)
테스트 23 〉	통과 (0.02ms, 4.27MB)
테스트 24 〉	통과 (0.02ms, 3.71MB)
테스트 25 〉	통과 (0.02ms, 4.32MB)
테스트 26 〉	통과 (0.02ms, 3.79MB)
테스트 27 〉	통과 (0.01ms, 4.27MB)
테스트 28 〉	통과 (0.02ms, 3.82MB)
테스트 29 〉	통과 (0.02ms, 4.2MB)
테스트 30 〉	통과 (0.02ms, 4.34MB)
테스트 31 〉	통과 (0.02ms, 4.31MB)
테스트 32 〉	통과 (0.02ms, 4.19MB)
*/

#include <string>
#include <cmath>

using namespace std;

// 3번 점수의 합

int solution(string dartResult) {
    int answer = 0;

    int power = 1;
    bool star = false;
    bool star_prev = false;
    bool acha = false;
    
    int idx = dartResult.length() - 1;
    while (idx >= 0) {
        while (!isdigit(dartResult[idx])) {
            if (dartResult[idx] == '*') star = true;
            if (dartResult[idx] == '#') acha = true;
            if (dartResult[idx] == 'S') power = 1;
            else if (dartResult[idx] == 'D') power = 2;
            else if (dartResult[idx] == 'T') power = 3;
            idx--;
        }
        
        int num = dartResult[idx] - '0';
        if (num == 0 && isdigit(dartResult[idx - 1])) { num = 10; idx--; }
        
        answer += (pow(num, power) * (star == true ? 2 : 1) * (star_prev == true ? 2 : 1) * (acha == true ? -1 : 1));
        star_prev = star;
        star = false;
        acha = false;
        idx--;
    }
    
    return answer;
}
