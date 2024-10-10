class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<vector<int>> nadj(n);
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            nadj[v].push_back(u);
        }

        unordered_set<int> l;
        vector<int> vis(n);
        queue<int> q;
        q.push(k);
        vis[k] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            l.insert(x);
            for (int y : adj[x]) {
                if (vis[y]) continue;
                q.push(y);
                vis[y] = 1;
            }
        }

        bool ok = true;
        for (int x : l) {
            for (int y : nadj[x]) {
                if (l.count(y) == 0) ok = false;
            }
        }
        if (!ok) l.clear();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (l.count(i)) continue;
            ans.push_back(i);
        }

        return ans;
    }
};
