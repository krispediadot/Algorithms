// 6.2 MB, 0ms
class Solution {
public:
    string customSortString(string order, string s) {
        string answer = "";

        for (auto& target : order) {
            auto itr = s.find(target);
            while (itr != string::npos) {
                int idx = itr;
                answer += target;
                s.erase(idx,1);

                itr = s.find(target);
            } 
        }

        answer += s;

        return answer;
    }
};

// 6.8 MB, 0ms
class Solution {
public:
    string customSortString(string order, string s) {
        vector<bool> used(26, false);
        string answer = "";

        for (auto& target : order) {
            string sub = s;
            auto itr = sub.find(target);
            while (itr != string::npos) {
                int idx = itr;
                answer += target;

                sub = sub.substr(idx+1);

                itr = sub.find(target);
            }

            used[target-'a'] = true;    
        }

        for (auto& c : s) {
            if (used[c-'a'] == false) answer += c;
        }

        return answer;
    }
};
