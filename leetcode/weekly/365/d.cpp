class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) adj[edges[i]].push_back(i);
        vector<int> ans(n);
        
        for (int j = 0; j < n; j++) {
            if (ans[j] != 0) continue;
            vector<int> time(n, -1);
            int circle = 0, cnt = 0;
            for (int i = j; ; i = edges[i], cnt++) {
                if (time[i] != -1) {
                    circle = cnt - time[i];
                    break;
                }
                time[i] = cnt;
            }
            
            unordered_set<int> st;
            for (int i = 0; i < n; i++) {
                if (time[i] < cnt && time[i] >= cnt - circle) {
                    ans[i] = circle;
                    st.insert(i);
                }
            }
            
            auto dfs = [&](auto self, int x) -> void {
                for (int y : adj[x]) {
                    if (ans[y] != 0) continue;
                    ans[y] = ans[x] + 1;
                    self(self, y);
                }
            };
            
            for (int z : st) dfs(dfs, z);
            
        }
        
        return ans;
    }
};
