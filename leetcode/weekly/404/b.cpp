class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, p = (nums[0] % 2) ^ 1, cur = 1, cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == p) cur += 1, p ^= 1;
        }
        ans = max(ans, cur);
        for (int i = 0; i < n; i++) {
            cnt += nums[i] % 2;
        }
        ans = max({ans, cnt, n - cnt});
        return ans;
    }
};
