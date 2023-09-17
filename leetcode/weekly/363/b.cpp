// https://leetcode.cn/problems/happy-students/

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < i + 1) {
                if (i < nums.size() - 1) {
                    if (nums[i + 1] > i + 1) ans++;
                } else ans++;
            }
        }
        if (nums[0] != 0) ans++;
        return ans;
    }
};
