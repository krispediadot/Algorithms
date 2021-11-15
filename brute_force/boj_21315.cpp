// 2340 KB, 0ms

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void swapper(vector<int>& init, int& n, int k) {
    int nSwap = pow(2, k);
    int prev = n;

    while (nSwap > 0) {
        vector<int> temp(n);

        int r = prev - 1;
        int l = r - nSwap + 1;

        for (int i = 0; i < prev; i++) {
            if (i < l) temp[nSwap+i] = init[i];
            else temp[i-l] = init[i];
        }
        for (int i = prev; i < n; i++) {
            temp[i] = init[i];
        }
 
        init = temp;
        prev = nSwap;
        nSwap /= 2;
    }
}

bool check(vector<int>& cards, int& n, int k1, int k2) {
    vector<int> init(n);
    for (int i = 1; i <= n; i++) init[i-1] = i;

    // k1
    swapper(init, n, k1);

    // k2
    swapper(init, n, k2);

    for (int i = 0; i < n; i++) {
        if (cards[i] != init[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) cin >> cards[i];
    
    int k1 = 1;
    int k2 = 1;

    for (; pow(2,k1) < n; k1++) {
        bool done = false;
        for (k2 = 1; pow(2,k2) < n; k2++) {
            if (check(cards, n, k1, k2)) {
                done = true;
                break;
            }
        }
        if (done) break;
    }

    cout << k1 << ' ' << k2;

    return 0;
}
