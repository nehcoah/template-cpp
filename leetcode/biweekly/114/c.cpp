class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int And = nums[0], n = nums.size();
        for (int i = 1; i < n; i++) And &= nums[i];
        if (And != 0) return 1;
        
        int ans = 0;
        int cur = nums[0];
        for (int i = 1; i < n; i++) {
            if (cur == 0) ans++, cur = nums[i];
            else cur &= nums[i];
        }
        if (cur == 0) ans++;
        return ans;
    }
};
