// 5928 KB,	472ms
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000001;

int main() {

	int N, K; cin >> N >> K;
	vector<int> cnts(MAX, 0);
	int maxNum = 0;

	while (N--) {
		int start, end; cin >> start >> end;
		for (int i = start + 1; i <= end; i++) cnts[i]++;

		maxNum = (end > maxNum) ? end : maxNum;
	}

	int A = 0, B = 0;
	int sum = 0;

	while(A <= B && B <= maxNum) {
		if (sum == K) break;

		if (sum < K) {
			B++;
			sum += cnts[B];
		}
		else {
			A++;
			sum -= cnts[A];
		} 
	}

	if (B > maxNum) cout << 0 << " " << 0 << '\n';
	else cout << A << " " << B << '\n';

	return 0;
}
