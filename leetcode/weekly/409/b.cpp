class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        
        auto check = [&]() {
            vector<int> f(n, n + 1);
            f[0] = 0;
            for (int i = 0; i < n; i++) {
                for (int x : adj[i]) {
                    f[x] = min(f[x], f[i] + 1);
                }
            }
            return f.back();
        };
        
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        
        vector<int> ans;
        for (auto &q : queries) {
            adj[q[0]].push_back(q[1]);
            ans.push_back(check());
        }
        return ans;
    }
};
