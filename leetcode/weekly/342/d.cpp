// https://leetcode.cn/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size(), count1 = 0;
        for (int x : nums) if (x == 1) count1++;
        if (count1) return n - count1;
        for (int i = 0; i < n; i++){
            int d = nums[i];
            for (int j = i + 1; j < n; j++){
                d = gcd(d, nums[j]);
                if (d == 1) ans = min(ans, j - i);
            }
        }
        if (ans == INT_MAX) return -1;
        ans += n - 1;
        return ans;
    }
};
