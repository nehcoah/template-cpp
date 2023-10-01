class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);
        int mx = nums[0];
        for (int i = 1; i < n; i++) {
            a[i] = max(a[i], mx - nums[i]);
            mx = max(mx, nums[i]);
        }
        long long ans = 0;
        mx = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            ans = max(ans, (long long)a[i] * mx);
            mx = max(mx, nums[i]);
        }
        return ans;
    }
};
