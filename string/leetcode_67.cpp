// 6.6MB, 2ms

class Solution {
public:
    string addBinary(string a, string b) {
        int len = (a.length() > b.length() ? a.length() : b.length());

        while (a.length() < len) a = '0' + a;
        while (b.length() < len) b = '0' + b;

        string answer = "";
        int lastCarry = 0;
        int carry = 0;
        int currbit = 0;

        for (int i = len-1; i >= 0; i--) {
            currbit = (a[i] - '0') ^ (b[i] - '0');
            carry = ((a[i] - '0') & (b[i] - '0')) || (currbit & lastCarry);

            answer.insert(0, 1, ((lastCarry + currbit) % 2 + '0'));
            lastCarry = carry;
        }
        if (carry == 1) answer = '1' + answer;

        return answer;
    }
};

// 6.4MB, 7ms

class Solution {
public:
    string addBinary(string a, string b) {
        int len = (a.length() > b.length() ? a.length() : b.length());

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        while (a.length() < len) a += '0';
        while (b.length() < len) b += '0';


        string answer = "";
        int lastCarry = 0;
        int carry = 0;
        int currbit = 0;

        for (int i = 0; i < len; i++) {
            currbit = (a[i] - '0') ^ (b[i] - '0');
            carry = ((a[i] - '0') & (b[i] - '0')) || (currbit & lastCarry);

            answer += (lastCarry + currbit) % 2 + '0';
            lastCarry = carry;
        }
        if (carry == 1) answer += '1';

        reverse(answer.begin(), answer.end());

        return answer;
    }
};

// 6.4MB, 7ms

class Solution {
public:
    string addBinary(string a, string b) {
        int len = (a.length() > b.length() ? a.length() : b.length());

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        while (a.length() < len) a += '0';
        while (b.length() < len) b += '0';


        string answer = "";
        int lastCarry = 0;
        int carry = 0;
        int currbit = 0;

        for (int i = 0; i < len; i++) {
            currbit = (a[i] - '0') ^ (b[i] - '0');
            carry = ((a[i] - '0') & (b[i] - '0')) || (currbit & lastCarry);

            answer += (lastCarry + currbit) % 2 + '0';
            lastCarry = carry;
        }
        if (carry == 1) answer += '1';

        reverse(answer.begin(), answer.end());

        return answer;
    }
};
