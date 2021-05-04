class Solution1 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> answer;
        unordered_set<int> numbers;
        
        for (int i = 1; i <= nums.size(); i++)
            numbers.insert(i);
        
        for (auto n : nums) {
            auto itr = numbers.find(n);
            if (itr == numbers.end()) answer.push_back(n);
            else numbers.erase(itr);
        }
        answer.push_back(*numbers.begin());
        
        return answer;
    }
};

class Solution2 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> answer;
        vector<bool> flags(nums.size(), false);

        for (auto n : nums) {
            if (flags[n - 1] == true) answer.push_back(n);
            else flags[n - 1] = true;
        }

        for (int i = 0; i < flags.size(); i++) {
            if (flags[i] == false) {
                answer.push_back(i + 1);
                break;
            }
        }

        return answer;
    }
};
