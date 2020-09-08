#include <iostream>

using namespace std;
int i, c; string s;
int main() {
    cin >> s;
    for (i = 0; i < s.size(); i++)
        while (isupper(s[i]) && (i + c) % 4 != 0) c++;
    cout << c << endl;
}