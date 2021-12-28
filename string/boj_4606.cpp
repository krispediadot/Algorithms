// 2032KB, 0ms
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unordered_map<string, string> dict = { {" ", "%20"},
                                           {"!", "%21"},
                                           {"$", "%24"},
                                           {"%", "%25"},
                                           {"(", "%28"},
                                           {")", "%29"},
                                           {"*", "%2a"}
                                         };

    string s = "";

    while (1) {
        getline(cin, s);

        if (s == "#") break;

        for (int i = 0; i < s.length(); i++) {
            if (dict.find(s.substr(i,1)) != dict.end()) {
                s = s.substr(0, i) + dict[s.substr(i,1)] + s.substr(i+1);
            }
        }

        cout << s << '\n';
    }

    return 0;
}
