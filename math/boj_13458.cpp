#include <iostream>
#include <vector>

using namespace std;

int N, B, C;
vector<int> people;

int main() {
    long long  answer = 0;
    cin >> N;

    people.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> people[i];

    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        people[i] -= B;
        answer++;

        if (people[i] > 0)
            answer += (people[i] / C + (people[i] % C == 0 ? 0 : 1));
    }

    cout << answer << endl;
}
