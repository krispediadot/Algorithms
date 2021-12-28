// 2024KB, 0ms
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int t = 0; t < 3; t++) {
        string a, b; cin >> a >> b;

        int s_h=stoi(a.substr(0, 2));
        int s_m=stoi(a.substr(3, 2));
        int s_s=stoi(a.substr(6, 2));
        int e_h=stoi(b.substr(0, 2));
        int e_m=stoi(b.substr(3, 2));
        int e_s=stoi(b.substr(6, 2));

        int cnt = 0;
        bool isOver = false;

        int s = s_h*10000 + s_m*100 + s_s;
        int e = e_h*10000 + e_m*100 + e_s;

        if (e % 3 == 0) cnt++;

        while (s != e) {
            if (s % 3 == 0) cnt++;

            s_s++;
            if (s_s == 60) {
                s_s = 0;
                s_m++;

                if (s_m == 60) {
                    s_m = 0;
                    s_h++;

                    if (s_h == 24) s_h = 0;
                }
            }

            s = s_h*10000 + s_m*100 + s_s;
            e = e_h*10000 + e_m*100 + e_s;
        }   
    
        cout << cnt << '\n';
    }

    return 0;
}
