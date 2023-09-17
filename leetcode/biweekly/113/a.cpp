// https://leetcode.cn/problems/minimum-right-shifts-to-sort-the-array/description/

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        bool f = 0;
        for (int i = 0; i < n - 1; i++) if (nums[i] > nums[i + 1]) {
            f = 1;
            break;
        }
        if (!f) return 0;
        if (nums[0] < nums.back()) return -1;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && nums[i] > nums[i + 1]) {
                if (ans == -1) ans = i + 1;
                else return -1;
            }
        }
        return n - ans;
    }
};
