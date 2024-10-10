class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end()), n = nums.size();
        vector<int> cnt(mx + 1);
        for (int i = 0; i < n; i++) {
            cnt[nums[i]] += 1;
        }

        vector<long long> g(mx + 1);
        for (int i = mx; i; i--) {
            long long tot = cnt[i];
            for (int x = 2 * i; x <= mx; x += i) {
                g[i] -= g[x];
                tot += cnt[x];
            }
            g[i] += 1ll * tot * (tot - 1) / 2;
        }

        for (int i = 1; i <= mx; i++) {
            g[i] += g[i - 1];
        }

        vector<int> ans;
        for (auto q : queries) {
            int p = upper_bound(g.begin(), g.end(), q) - g.begin();
            ans.push_back(p);
        }
        return ans;
    }
};
