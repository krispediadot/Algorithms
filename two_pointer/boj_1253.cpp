// 2020 KB, 16ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cnts = 0;
	int N; cin >> N;
	vector<int> nums(N);
	for (int i = 0 ; i < N; i++) cin >> nums[i];

	sort(nums.begin(), nums.end());

	for (int i = 0; i < N; i++) {
		int& target = nums[i];
		int left = 0, right = N - 1;

		while (left < right) {
			int sum = nums[left] + nums[right];

			if (sum < target) left++;
			else if (sum > target) right--;
			else {
				if (left == i) left++;
				else if (right == i) right--;
				else {
					cnts++;
					break;
				}
			}
		}
	}
	
	cout << cnts;

	return 0;
}
