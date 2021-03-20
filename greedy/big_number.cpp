#include <iostream>
#include <string>
#include <vector>

using namespace std;

// k개의 수를 제거힐 때 얻을 수 있는 가장 큰 수
string solution(string number, int k) {
    string answer = "";

    while (k--) {
        bool replaced = false;
        for (int i = 0; i < number.length() - 1; i++){
            if (number[i] < number[i + 1]){
                number.replace(i, 1, "");
                replaced = true;
                break;
            }
        }
        if (!replaced) number.replace(number.length() - 1, 1, "");
    }

    return number;
}

int main() {
    cout << solution("1924", 2) << endl; // 94
    cout << solution("1231234", 3) << endl; // 3234
    cout << solution("4177252841", 4) << endl; // 775841
    cout << solution("147725431", 4) << endl; // 77543
    cout << solution("147725431", 5) << endl; // 7754
}
