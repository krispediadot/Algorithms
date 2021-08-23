// 7588 KB,	64 ms
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K; cin >> N >> K;
	vector<int> nums(N);
	unordered_map<int, int> cnts;

	int maxLen = 0;
	int startIdx = 0;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];

		if (cnts[nums[i]] >= K) {
			maxLen = max(maxLen, i - startIdx);
			while (nums[startIdx] != nums[i] && startIdx < i) {
				cnts[nums[startIdx]]--;
				startIdx++;
			}
			cnts[nums[i]]--;
			startIdx++;
		}

		cnts[nums[i]]++;
	}

	maxLen = max(maxLen, N - startIdx);

	cout << maxLen;

	return 0;
} 
