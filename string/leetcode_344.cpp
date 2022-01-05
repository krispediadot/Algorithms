// 23.3MB, 33ms
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l <= r) {
            swap(s[l++], s[r--]);
        }
    }
};

// 23.3MB, 33ms
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l <= r) {
            swap(s[l++], s[r--]);
        }
    }
};

// 23.1MB, 16ms
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
