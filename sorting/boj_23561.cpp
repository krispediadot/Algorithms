//3192 KB, 52ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> ages(3*n); 

    for (int i = 0; i < 3*n; i++) cin >> ages[i];
    
    sort(ages.begin(), ages.end(), greater<int>());

    cout << ages[n] - ages[2*n-1] << '\n';

    return 0;
}
