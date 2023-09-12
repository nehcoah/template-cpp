// 2843
// https://leetcode.cn/problems/count-symmetric-integers/description/
// brute force

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int c = low; c <= high; c++) {
            string s = to_string(c);
            if (s.size() % 2 == 1) continue;
            int pre = 0, suf = 0;
            for (int i = 0; i < s.size() / 2; i++) {
                pre += int(s[i] - '0');
                suf += int(s[s.size() - i - 1] - '0');
            }
            ans += pre == suf;
        }
        return ans;
    }
};
