// 4452KB, 300ms
#include <iostream>
#include <queue>

using namespace std;

struct Work {
    int id;
    int t;
    int prio;
};

struct cmp {
    bool operator()(Work a, Work b) {
        if (a.prio == b.prio)
            return a.id > b.id;
        return a.prio < b.prio;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, n; cin >> T >> n;

    priority_queue<Work, vector<Work>, cmp> pq;

    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        
        Work w;
        w.id = a;
        w.t = b;
        w.prio = c;

        pq.push(w);
    }

    while (T-- && !pq.empty()) {
        auto target = pq.top(); pq.pop();
        cout << target.id << '\n';

        target.t--;
        target.prio--;

        if (target.t > 0)
            pq.push(target);
    }

    return 0;
}
