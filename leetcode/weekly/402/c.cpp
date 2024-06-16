class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> mp;
        for (int x : power) {
            mp[x] += 1;
        }
        long long ans = 0, mx = 0;
        queue<pair<int, long long>> info;
        for (auto [k, v] : mp) {
            long long w = 1ll * k * v;
            while (!info.empty() && info.front().first < k - 2) {
                mx = max(mx, info.front().second);
                info.pop();
            }
            ans = max(ans, mx + w);
            info.emplace(k, mx + w);
        }
        return ans;
    }
};
