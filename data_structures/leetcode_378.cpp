// 64ms, 22.6MB
// multiset 사용
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int> temp;
        
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                temp.insert(matrix[r][c]);
            }
        }
        
        auto itr = temp.begin();
        
        advance(itr, k - 1);
        
        return *itr;
    }
};

// 32ms, 14.5MB
// vector 하나로 모으고 sort
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> total;

        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                total.push_back(matrix[r][c]);
            }
        }

        sort(total.begin(), total.end());

        return total[k - 1];
    }
};

// 32ms, 14.3MB
// maxHeap 사용
class Solution3 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                pq.push(matrix[r][c]);

                if (pq.size() > k) pq.pop();
            }
        }

        return pq.top();
    }
};

//24ms, 13MB
//binary search 사용
class Solution4 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = matrix[0][0];
        int right = matrix[m - 1][n - 1];
        int answer = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (countLessOrEqual(matrix, mid) >= k) {
                answer = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return answer;
    }

    // x보다 작거나 같은 수의 개수 세기
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int cnt = 0;
        int c = matrix[0].size() - 1;

        for (int r = 0; r < matrix.size(); r++) {
            while (c >= 0 && matrix[r][c] > x) --c;
            cnt += (c + 1);
        }

        return cnt;
    }
};
