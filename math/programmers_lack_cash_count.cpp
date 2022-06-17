/*
테스트 1 〉	통과 (0.01ms, 3.86MB)
테스트 2 〉	통과 (0.01ms, 3.85MB)
테스트 3 〉	통과 (0.01ms, 3.74MB)
테스트 4 〉	통과 (0.01ms, 3.75MB)
테스트 5 〉	통과 (0.01ms, 3.97MB)
테스트 6 〉	통과 (0.01ms, 3.97MB)
테스트 7 〉	통과 (0.01ms, 3.73MB)
테스트 8 〉	통과 (0.01ms, 3.98MB)
테스트 9 〉	통과 (0.02ms, 3.74MB)
테스트 10 〉	통과 (0.01ms, 3.74MB)
테스트 11 〉	통과 (0.01ms, 4.31MB)
테스트 12 〉	통과 (0.01ms, 3.75MB)
테스트 13 〉	통과 (0.01ms, 3.98MB)
테스트 14 〉	통과 (0.01ms, 4.32MB)
테스트 15 〉	통과 (0.01ms, 3.98MB)
테스트 16 〉	통과 (0.01ms, 3.75MB)
테스트 17 〉	통과 (0.01ms, 3.73MB)
테스트 18 〉	통과 (0.01ms, 3.97MB)
테스트 19 〉	통과 (0.01ms, 3.98MB)
테스트 20 〉	통과 (0.01ms, 3.98MB)
테스트 21 〉	통과 (0.01ms, 3.73MB)
테스트 22 〉	통과 (0.01ms, 3.75MB)
테스트 23 〉	통과 (0.01ms, 4.34MB)
*/

using namespace std;

long long solution(int price, int money, int count)
{
    long long totalPrice = (1 + count) * (count / 2);
    
    if (count % 2 == 1) totalPrice += (count / 2 + 1);
    
    totalPrice *= price;

    return (totalPrice - money <= 0) ? 0 : totalPrice - money;
}
