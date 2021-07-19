// 2180KB, 4ms
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	while (n--) {
		int num; cin >> num;
		
		vector<int> answer(num + 1, 1);

		for (int term = 2; term <= 3; term++) {
			for (int i = term; i <= num; i++) {
				answer[i] += answer[i - term];
			}
		}

		cout << answer[num] << '\n';
	}

	return 0;
}
