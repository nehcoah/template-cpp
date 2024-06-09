class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> f;
        vector<set<pair<int, int>>> st(k + 1);
        int ans = 0;
        for (int x : nums) {
            if (f[x].empty()) f[x] = vector<int>(k + 1);
            for (int i = k; i >= 0; i--) {
                auto itx = st[i].find(make_pair(f[x][i], x));
                if (itx != st[i].end()) st[i].erase(itx);
                f[x][i] += 1;
                if (i) {
                    if (st[i - 1].empty()) continue;
                    auto it = prev(st[i - 1].end());
                    if (it->second == x) {
                        if (it == st[i - 1].begin()) continue;
                        it = prev(it);
                    }
                    f[x][i] = max(f[x][i], f[it->second][i - 1] + 1);
                }
                st[i].emplace(f[x][i], x);
                if (st[i].size() > 2) st[i].erase(st[i].begin());
                ans = max(ans, f[x][i]);
            }
        }
        return ans;
    }
};
