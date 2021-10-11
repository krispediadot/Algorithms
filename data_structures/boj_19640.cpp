// 10316 KB, 56ms

// M 개의 줄을 vector로 구현 후 인덱스만 이동하기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
struct cmp {

    // D 높을수록, H 높을수록, line idx 낮을수록 우선

    bool operator()(pair<pair<int, int>,int>& a, pair<pair<int, int>,int>& b) {
        if (a.first.first == b.first.first) {
            if (a.first.second == b.first.second) 
                return a.second > b.second;
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
};

int main() {

    // 1. input

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, K; cin >> N >> M >> K;

    pair<int, int> DECA = {-1, -1}; // line idx, elem idx 

    vector<vector<pair<int, int>>> lines(M);
    vector<int> linesIdx(M, 0);

    for (int i = 0; i < N; i++) {
        int targetIdx = i % M;
        pair<int, int> person; cin >> person.first >> person.second;
        lines[targetIdx].push_back(person);

        if (i == K) DECA = {targetIdx, (int)lines[targetIdx].size()-1};
    }

    // 2. logic

    // 2-1. 각 줄의 첫번째 사람 정보 넣기
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq; // info(D, H), lineIdx
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()) {
            pq.push({lines[i].front(), i});
            linesIdx[i]++;
        }
    }

    int answer = 0;

    // 2-2. 우선순위대로 빼기
    while (!(pq.top().second == DECA.first && DECA.second == 0)) {
        auto target = pq.top(); pq.pop();

        // DECA인지 아닌지 확인하기 위해 DECA의 elem idx 빼기(elem idx==0이되면 DECA임)
        if (target.second == DECA.first) DECA.second--;

        answer++;
        
        // M 개의 각 줄에 사람이 있는지 없는지 확인 
        if (linesIdx[target.second] < lines[target.second].size()) {
            pq.push({lines[target.second][linesIdx[target.second]], target.second});
            linesIdx[target.second]++;
        }
    } 

    // 3. output

    cout << answer;

    return 0;
}

// 10316 KB, 48ms
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        if (a.first.first == b.first.first) {
            if (a.first.second == b.first.second) {
                return a.second > b.second;
            }
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
};

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M, K; cin >> N >> M >> K;

    vector<vector<pair<int, int>>> lines(M);
    vector<int> linesIdx(M, 0); // 선두 확인용

    pair<int, int> DECA = {-1, -1}; // {targetLine, idx}

    for (int i = 0; i < N; i++) {
        int D, H; cin >> D >> H;

        int targetLine = i % M;
        lines[targetLine].push_back({D, H});

        if (i == K) DECA = {targetLine, lines[targetLine].size()-1};
    }

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;
    
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()){
            pq.push({lines[i][0], i});
            linesIdx[i]++;
        }
    } 

    int answer = 0;

    while (!(pq.top().second == DECA.first && DECA.second == 0)) {
        auto target = pq.top(); pq.pop();
        int& line = target.second;

        if (line == DECA.first) DECA.second--;
        
        answer++;

        if (linesIdx[line] < lines[line].size())
            pq.push({lines[line][linesIdx[line]++], line});
    }

    cout << answer << '\n';

    return 0;
}
