// https://leetcode.cn/problems/apply-operations-to-make-all-array-elements-equal-to-zero/

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size(), cur = 0, diff[n + 1];
        memset(diff, 0, sizeof(diff));
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            int x = nums[i] + cur;
            if (x == 0) continue;
            if (x < 0 || i + k > n) return false;
            cur -= x;
            diff[i + k] += x;
        }
        return true;
    }
};
