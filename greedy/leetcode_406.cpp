// 80ms, 14MB, 1:17:00
class Solution1 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        vector<vector<int>> answer;
        list<vector<int>> l;

        // 1. descending order
        auto comp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        };
        sort(people.begin(), people.end(), comp);
        
        for (auto& person : people) {
            if (l.empty()) {
                l.push_back(person);
                continue;
            }
            
            int height = person[0];
            int limit = person[1];
            
            // 2. find correct location for this person
            auto itr = l.begin();
            vector<int> target = *itr;
            int cnt_taller = 0;
            
            while (cnt_taller < limit && itr != l.end()) {
                target = *itr;
                if (target[0] >= height)
                    cnt_taller++;
                itr++;
            }
            
            // 3. insert person
            if (itr == l.end()) l.push_back(person);
            else l.insert(itr, person);
        }
        
        for (auto itr = l.begin(); itr != l.end(); itr++) {
            answer.push_back(*itr);
        }
        
        return answer;
    }
};

// 72ms, 13.6MB, 1:30:00
class Solution2 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        list<vector<int>> l;

        // 1. descending order
        auto comp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        };
        sort(people.begin(), people.end(), comp);

        for (auto& person : people) {
            if (l.empty()) {
                l.push_back(person);
                continue;
            }

            int height = person[0];
            int limit = person[1];

            // 2. find correct location for this person
            auto itr = l.begin();
            vector<int> target = *itr;
            int cnt_taller = 0;

            while (cnt_taller < limit && itr != l.end()) {
                target = *itr;
                if (target[0] >= height)
                    cnt_taller++;
                itr++;
            }

            // 3. insert person
            if (itr == l.end()) l.push_back(person);
            else l.insert(itr, person);
        }

        return vector<vector<int>> (l.begin(), l.end());
    }
};

// 28ms, 13.1MB, 1:40:00
class Solution3 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        list<vector<int>> l;

        // 1. descending order
        auto comp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        };
        sort(people.begin(), people.end(), comp);

        // 2. insert people
        for (auto& person : people) {
            if (person[1] == 0) {
                l.push_front(person);
            }
            else if(person[1] > l.size()) {
                l.push_back(person);
            }
            else {
                auto itr = l.begin();
                advance(itr, person[1]);
                l.insert(itr, person);
            }
        }

        return vector<vector<int>> (l.begin(), l.end());
    }
};

// 72ms, 11.8MB, 1:50:00
class Solution4 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        vector<vector<int>> answer(people.size(), vector<int>(2, -1));

        // 1. descending order
        auto comp = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };
        sort(people.begin(), people.end(), comp);

        // 2. insert people
        for (auto& person : people) {
            int limit = person[1];

            for (int i = 0; i < answer.size(); i++) {
                if (answer[i][0] == -1 && limit == 0) {
                    answer[i][0] = person[0];
                    answer[i][1] = person[1];
                    break;
                }
                else {
                    if (answer[i][0] == -1 || answer[i][0] >= person[0]) {
                        limit--;
                    }
                }
            }
        }

        return answer;
    }
};
