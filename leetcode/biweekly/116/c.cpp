class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> f(target + 1, -1);
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; j--) {
                if (f[j - x] != -1) f[j] = max(f[j], f[j - x] + 1);
            }
        }
        return f[target];
    }
};
