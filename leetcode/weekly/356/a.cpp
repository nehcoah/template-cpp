// 2798
// https://leetcode.cn/problems/number-of-employees-who-met-the-target/description/
// brute force

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (int h : hours) if (h >= target) ans++;
        return ans;
    }
};
