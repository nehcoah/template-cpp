// 2791
// https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/
// tree, bitmask

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size(), sum[n];
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) adj[parent[i]].push_back(i);
        auto dfs = [&](auto self, int i, int cur) -> void {
            sum[i] = cur;
            for (int x : adj[i]) {
                self(self, x, cur ^ (1 << (s[x] - 'a')));
            }
        };
        dfs(dfs, 0, 0);
        long long ans = 0;
        unordered_map<int, int> mp;
        for (int x : sum) {
            ans += mp[x];
            for (int i = 0; i < 26; i++) ans += mp[x ^ (1 << i)];
            mp[x]++;
        }
        return ans;
    }
};
