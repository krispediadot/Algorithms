// 2516KB, 0ms
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int z; cin >> z;
    
    for (int i = 0; i < z; i++) {
        int idx, itr; cin >> idx >> itr;
        string s; cin >> s;

        for (int j = 0; j < itr; j++) {
            string sub = s.substr(idx);
            s = sub + s;
        }

        cout << s << '\n';
    }

    return 0;
}
