// 2024KB, 0ms
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int m = stoi(s.substr(0, 2));
    int sec = stoi(s.substr(3, 2));
    sec += (m*60);

    if (sec < 30) cout << (sec/10)+1 << '\n';
    else {

        // 시작 30분 없이

        int sec_copy = sec; int copy_cnt = 1;
        copy_cnt += (sec_copy/600); sec_copy %= 600;
        copy_cnt += (sec_copy/60); sec_copy %= 60;
        copy_cnt += (sec_copy/30); sec_copy %= 30;
        copy_cnt += (sec_copy/10); sec_copy %= 10;
        
        // 시작 30분 추가

        sec -= 30; int sec_cnt = 1;
        sec_cnt += (sec/600); sec %= 600;
        sec_cnt += (sec/60); sec %= 60;
        sec_cnt += (sec/30); sec %= 30;
        sec_cnt += (sec/10); sec %= 10;
        
        cout << min(copy_cnt, sec_cnt) << '\n';
    }

    return 0;
}
