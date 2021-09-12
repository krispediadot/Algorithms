// 6048 KB,	408ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 100000001;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;

	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> numbers(n);
		pair<int, int> answer = { 2 * MAX, 0 }; // { gap from k, cnt}
		for (int i = 0; i < n; i++) cin >> numbers[i];

		sort(numbers.begin(), numbers.end());

		int l = 0, r = n - 1;
		while (l < r) {
			int sub = numbers[l] + numbers[r];
			if (abs(k - sub) == answer.first) answer.second++;
			if (abs(k - sub) < answer.first) answer = { abs(k - sub), 1 };

			if (sub <= k) l++;
			else r--;
		}
		
		cout << answer.second << '\n';
	}

	return 0;
}
