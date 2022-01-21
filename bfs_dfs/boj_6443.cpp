// 2024KB, 60ms
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generator(vector<int>& alphabets, string result, int left) {
    if (left == 0) {
        cout << result << '\n';
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabets[i] > 0) {
            alphabets[i]--;
            generator(alphabets, result+char('a'+i), left-1);
            alphabets[i]++;
        }
    }
}

void solution(string s) {
    vector<int> alphabets(26, 0);
    for (auto c : s) alphabets[c-'a']++;

    generator(alphabets, "", s.length());
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    
    while (n--) {
        string s; cin >> s;
        solution(s);
    }

    return 0;
}

// 12192KB, 92ms
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solution(string s) {
    set<string> sets;
    
    sort(s.begin(), s.end());

    do {
        sets.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    for (auto item : sets) cout << item << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    
    while (n--) {
        string s; cin >> s;
        solution(s);
    }

    return 0;
}
