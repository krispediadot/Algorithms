// 3980 KB, 12ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> arr(n);
	vector<int> aggSum_1(n);
	vector<int> aggSum_2(n);
	vector<int> aggSum_1_reverse(n+1);
	vector<int> aggSum_2_reverse(n+1);

	int sumMid = 0;
	int max_idx = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i > 0 && i < n-1) {
			if (arr[max_idx] < arr[i]) max_idx = i;
			sumMid += arr[i];
		}
		if (i > 0) aggSum_1[i] = aggSum_1[i-1] + arr[i];
		if (i < n-1) aggSum_2[i] = aggSum_2[i-1] + (arr[i]*2);
	}
	sumMid += arr[max_idx];

	for (int i = n-1; i >= 0; i--) {
		if (i < n-1) aggSum_1_reverse[i] = aggSum_1_reverse[i+1] + arr[i];
		if (i > 0) aggSum_2_reverse[i] = aggSum_2_reverse[i+1] + (arr[i]*2);
	}

	int answer = 0;

	// 벌통 오/ 왼
	for (int i = 1; i < n-1; i++) {
		answer = max(answer, aggSum_1[i-1] + aggSum_2_reverse[i+1]);
		answer = max(answer, aggSum_1_reverse[i+1] + aggSum_2[i-1]);
	}

	// 벌통 중
	answer = max(answer, sumMid);

	cout << answer << '\n';

	return 0;
}
