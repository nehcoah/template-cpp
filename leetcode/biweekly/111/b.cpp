// 2825
// https://leetcode.cn/problems/make-string-a-subsequence-using-cyclic-increments/description/
// greedy

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if (n1 < n2) return false;
        int i = 0, j = 0;
        for (; i < n1 && j < n2; i++) {
            if (str1[i] == str2[j] || str1[i] + 1 == str2[j]) j++;
            else if (str1[i] == 'z' && str2[j] == 'a') j++;
        }
        return j == n2;
    }
};
