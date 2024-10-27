class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](int x) {
            long long g = 0, l = 0;
            for (int i = 0; i < n; i++) {
                if (i == x) continue;
                g = g == 0 ? nums[i] : gcd(g, nums[i]);
                l = l == 0 ? nums[i] : lcm(l, nums[i]);
            }
            return 1ll * g * l;
        };

        long long ans = check(-1);
        for (int i = 0; i < n; i++) {
            ans = max(ans, check(i));
        }
        return ans;
    }
};
