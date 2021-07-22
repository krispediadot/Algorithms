// 2412KB, 16ms
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 두 용액을 합쳐 0에 가까운 용액 만들기 

int binarySearch(vector<int>& elements) {

    if (elements.back() < 0) return elements.size() + 1;
    if (elements.front() > 0) return 0;

    int left = 0;
    int right = elements.size() - 1;

    while (left + 1 < right) {
        int mid = (left + right) / 2;

        if (elements[mid - 1] < 0 && elements[mid] >= 0)
            return mid;

        if (elements[mid] < 0) left = mid;
        else right = mid;
    }

    return right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> elements(n);
    for (int i = 0 ; i < n; i++) cin >> elements[i];

    pair<int, int> answer;

    // 첫번째 알칼리(양수)의 인덱스
    int midIdx = binarySearch(elements);

    // 알칼리(음수)만 있다면
    if (midIdx > elements.size() - 1)
        answer = {elements[elements.size() - 2], elements[elements.size() - 1]};
    
    // 산성(양수)만 있다면
    else if (midIdx <= 0)
        answer = {elements[0], elements[1]};

    // 모든 경우의 수 살펴보기
    else {
        int left = midIdx - 1;
        int right = midIdx;
        int minSum = abs(elements[left] + elements[right]);
        answer = {elements[left], elements[right]};

        while (left >= 0 && right < elements.size()) {
            int sub = elements[left] + elements[right];

            // 알칼리(음수)만으로 더 작은 값을 생성할 수 있다면 
            if (abs(elements[left]) < abs(minSum)) {
                if (left > 0 && (abs(elements[left - 1] + elements[left]) < abs(minSum))) {
                    answer = {elements[left - 1], elements[left]};
                    minSum = abs(elements[left - 1] + elements[left]);
                }
            }

            // 산성(양수)만으로 더 작은 값을 생성할 수 있다면
            if (abs(elements[right]) < abs(minSum)) {
                if (right < elements.size() - 1 && (abs(elements[right] + elements[right + 1]) < abs(minSum))) {
                    answer = {elements[right], elements[right + 1]};
                    minSum = abs(elements[right] + elements[right + 1]);
                }
            }
            
            if (abs(sub) < abs(minSum)) {
                answer = {elements[left], elements[right]};
                minSum = abs(sub);
            }

            if (sub < 0) right++;
            else left--;
        }
    }

    cout << answer.first << ' ' << answer.second;

    return 0;
}

// 2412KB, 64ms
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 두 용액을 합쳐 0에 가까운 용액 만들기 

int binarySearch(vector<int>& elements) {

    if (elements.back() < 0) return elements.size() + 1;
    if (elements.front() > 0) return 0;

    int left = 0;
    int right = elements.size() - 1;

    while (left + 1 < right) {
        int mid = (left + right) / 2;

        if (elements[mid - 1] < 0 && elements[mid] >= 0)
            return mid;

        if (elements[mid] < 0) left = mid;
        else right = mid;
    }

    return right;
}

int main() {
    int n; cin >> n;
    vector<int> elements(n);
    for (int i = 0 ; i < n; i++) cin >> elements[i];

    pair<int, int> answer;

    // 첫번째 알칼리(양수)의 인덱스
    int midIdx = binarySearch(elements);

    // 알칼리(음수)만 있다면
    if (midIdx > elements.size() - 1)
        answer = {elements[elements.size() - 2], elements[elements.size() - 1]};
    
    // 산성(양수)만 있다면
    else if (midIdx <= 0)
        answer = {elements[0], elements[1]};

    // 모든 경우의 수 살펴보기
    else {
        int left = midIdx - 1;
        int right = midIdx;
        int minSum = abs(elements[left] + elements[right]);
        answer = {elements[left], elements[right]};

        while (left >= 0 && right < elements.size()) {
            int sub = elements[left] + elements[right];

            // 알칼리(음수)만으로 더 작은 값을 생성할 수 있다면 
            if (abs(elements[left]) < abs(minSum)) {
                if (left > 0 && (abs(elements[left - 1] + elements[left]) < abs(minSum))) {
                    answer = {elements[left - 1], elements[left]};
                    minSum = abs(elements[left - 1] + elements[left]);
                }
            }

            // 산성(양수)만으로 더 작은 값을 생성할 수 있다면
            if (abs(elements[right]) < abs(minSum)) {
                if (right < elements.size() - 1 && (abs(elements[right] + elements[right + 1]) < abs(minSum))) {
                    answer = {elements[right], elements[right + 1]};
                    minSum = abs(elements[right] + elements[right + 1]);
                }
            }
            
            if (abs(sub) < abs(minSum)) {
                answer = {elements[left], elements[right]};
                minSum = abs(sub);
            }

            if (sub < 0) right++;
            else left--;
        }
    }

    cout << answer.first << ' ' << answer.second;

    return 0;
}
