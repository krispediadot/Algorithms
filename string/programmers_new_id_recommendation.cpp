/*
테스트 1 〉	통과 (0.12ms, 4.17MB)
테스트 2 〉	통과 (0.10ms, 4.12MB)
테스트 3 〉	통과 (0.10ms, 4.18MB)
테스트 4 〉	통과 (0.10ms, 4.1MB)
테스트 5 〉	통과 (0.11ms, 3.82MB)
테스트 6 〉	통과 (0.11ms, 4.18MB)
테스트 7 〉	통과 (0.17ms, 4.18MB)
테스트 8 〉	통과 (0.11ms, 4.16MB)
테스트 9 〉	통과 (0.11ms, 4.11MB)
테스트 10 〉	통과 (0.14ms, 4.26MB)
테스트 11 〉	통과 (0.12ms, 4.09MB)
테스트 12 〉	통과 (0.11ms, 4.17MB)
테스트 13 〉	통과 (0.11ms, 4.18MB)
테스트 14 〉	통과 (0.15ms, 4.25MB)
테스트 15 〉	통과 (0.12ms, 4.17MB)
테스트 16 〉	통과 (0.12ms, 4.18MB)
테스트 17 〉	통과 (0.13ms, 4.18MB)
테스트 18 〉	통과 (0.15ms, 4.18MB)
테스트 19 〉	통과 (0.19ms, 4.18MB)
테스트 20 〉	통과 (0.27ms, 3.88MB)
테스트 21 〉	통과 (0.20ms, 4.18MB)
테스트 22 〉	통과 (0.30ms, 4.19MB)
테스트 23 〉	통과 (0.23ms, 3.93MB)
테스트 24 〉	통과 (0.24ms, 4.18MB)
테스트 25 〉	통과 (0.23ms, 4.18MB)
테스트 26 〉	통과 (0.22ms, 4.04MB)
*/

#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id) {

    // 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    for (auto& c : new_id) c = tolower(c);

    // 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    new_id = regex_replace(new_id, regex("[^a-z0-9-_.]+"),"");

    // 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    new_id = regex_replace(new_id, regex("[.]+"),".");

    // 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if (new_id.front() == '.') new_id.erase(new_id.begin());
    if (new_id.back() == '.') new_id.erase(new_id.end()-1);

    // 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if (new_id.length() == 0) new_id = "a";

    // 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    //    만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if (new_id.length() >= 16) new_id = new_id.substr(0, 15);
    if (new_id.back() == '.') new_id.erase(new_id.end()-1);
    
    // 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    while (new_id.length() < 3) new_id.push_back(new_id.back());

    return new_id;
}
