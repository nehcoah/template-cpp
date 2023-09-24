// https://leetcode.cn/problems/maximum-odd-binary-number/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0, cnt0 = 0;
        for (char c : s) {
            if (c == '1') cnt1++;
            else cnt0++;
        }
        cnt1--;
        string ans;
        for (int i = 0; i < cnt1; i++) ans += '1';
        for (int i = 0; i < cnt0; i++) ans += '0';
        ans += '1';
        return ans;
    }
};
