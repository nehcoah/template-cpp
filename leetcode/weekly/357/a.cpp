// 2810
// https://leetcode.cn/problems/faulty-keyboard/
// brute force

class Solution {
public:
    string finalString(string s) {
        string ans;
        for (char c : s) {
            if (c == 'i') reverse(ans.begin(), ans.end());
            else ans.push_back(c);
        }
        return ans;
    }
};
