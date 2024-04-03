class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        using ll = long long;
        const int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        map<array<ll, 3>, ll> mp;
        auto dfs = [&](auto self, ll i, ll mn, ll t) -> ll {
            if (t == k) return mn;
            if (mp.count({i, mn, t})) return mp[{i, mn, t}];
            ll ans = 0;
            for (int j = i + 1; j + k - t <= n; j++) {
                ans = (ans + self(self, j, min(mn, 1ll * nums[j] - nums[i]), t + 1)) % mod;
            }
            return mp[{i, mn, t}] = ans;
        };
        
        ll ans = 0;
        for (int i = 0; i + k <= n; i++) {
            ans = (ans + dfs(dfs, i, 1e9, 1)) % mod;
        }
        return ans;
    }
};
