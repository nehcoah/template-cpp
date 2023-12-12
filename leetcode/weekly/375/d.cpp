class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        using ll = long long;
        unordered_map<int, vector<int>> mp;
        vector<pair<int, int>> t;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto [k, v] : mp) {
            if (v.size() > 1) t.emplace_back(v[0], v.back());
        }
        ranges::sort(t);
        
        int mod = 1e9 + 7;
        auto power = [&](ll x, ll y) {
            ll ans = 1;
            for (; y; y /= 2) {
                if (y & 1) ans = ans * x % mod;
                x = x * x % mod;
            }
            return ans;
        };
        
        if (t.empty()) return power(2, n - 1);
        auto [l, r] = t[0];
        int cnt = l;
        for (int i = 1; i < t.size(); i++) {
            if (t[i].second <= r) continue;
            else {
                if (t[i].first > r) {
                    cnt += t[i].first - r;
                    l = t[i].first, r = t[i].second;
                } else r = t[i].second;
            }
        }
        cnt += n - r;
        return power(2, cnt - 1);
    }
};
