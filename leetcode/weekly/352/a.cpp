// https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] > threshold || nums[i] % 2 == 1) continue;
            int j = i + 1;
            for (; j < n; j++){
                if (nums[j] > threshold || nums[j] % 2 == nums[j - 1] % 2) {
                    ans = max(ans, j - i);
                    break;
                }
            }
            if (j == n) ans = max(ans, j - i);
        }
        return ans;
    }
};
