// https://leetcode.cn/problems/longest-alternating-subarray/

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                int j = i, cnt = 0;
                while (j < n - 1) {
                    if (cnt == 0 && nums[j] + 1 == nums[j + 1]) j++, cnt = 1;
                    else if (cnt == 1 && nums[j] - 1 == nums[j + 1]) j++, cnt = 0;
                    else break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
