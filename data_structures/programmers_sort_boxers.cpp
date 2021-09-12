/*
테스트 1 〉	통과 (0.01ms, 4.26MB)
테스트 2 〉	통과 (0.01ms, 4.33MB)
테스트 3 〉	통과 (0.01ms, 4.26MB)
테스트 4 〉	통과 (0.01ms, 3.68MB)
테스트 5 〉	통과 (0.01ms, 4.32MB)
테스트 6 〉	통과 (2.56ms, 4.79MB)
테스트 7 〉	통과 (2.93ms, 5.11MB)
테스트 8 〉	통과 (2.94ms, 5.83MB)
테스트 9 〉	통과 (0.85ms, 4.25MB)
테스트 10 〉	통과 (0.57ms, 4.27MB)
테스트 11 〉	통과 (3.56ms, 5.52MB)
테스트 12 〉	통과 (0.79ms, 4.73MB)
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct playerInfo {
	int idx;
	float winningRate;
	int overweightCnt;
	int weight;
	playerInfo(int idx, float winning, int over, int weight) : idx(idx), winningRate(winning), overweightCnt(over), weight(weight) {}
};

struct cmp {
	bool operator()(playerInfo &a, playerInfo &b) {
		if (a.winningRate == b.winningRate) {
			if (a.overweightCnt == b.overweightCnt) {
				if (a.weight == b.weight) {
					return a.idx > b.idx;
				}
				return a.weight < b.weight;
			}
			return a.overweightCnt < b.overweightCnt;
		}
		return a.winningRate < b.winningRate;
	}
};

vector<int> solution(vector<int> weights, vector<string> head2head) {
	int nPlayer = weights.size();

	vector<int> answer;

	vector<float> winningRate(nPlayer, 0);
	vector<int> overweightCnt(nPlayer, 0);

	for (int i = 0; i < nPlayer; i++) {
		int gameCnt = 0;
		int wonCnt = 0;
		int overweightWonCnt = 0;
		for (int j = 0; j < nPlayer; j++) {
			if (head2head[i][j] != 'N') gameCnt++;
			if (head2head[i][j] == 'W') {
				wonCnt++;
				if (weights[j] > weights[i]) overweightWonCnt++;
			}
		}
		if (gameCnt > 0) winningRate[i] = ((float)wonCnt / gameCnt);
		overweightCnt[i] = (overweightWonCnt);
	}

	priority_queue<playerInfo, vector<playerInfo>, cmp> pq;
	for (int i = 0; i < nPlayer; i++) pq.push({ i+1, winningRate[i], overweightCnt[i], weights[i] });

	while (!pq.empty()) {
		auto target = pq.top(); pq.pop();
		answer.push_back(target.idx);
	}

	return answer;
}
