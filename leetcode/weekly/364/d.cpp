// https://leetcode.cn/problems/count-valid-paths-in-a-tree/

int N = 1e5 + 1;
vector<bool> isPrime;
auto init = [](){
    isPrime.resize(N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++){
        if (isPrime[i]){
            for (int j = i * 2; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (!isPrime[i + 1]) continue;
            
            int cnt = 0;
            auto dfs = [&](auto self, int x, int pa) -> void {
                if (isPrime[x + 1]) return;
                cnt++;
                for (int y : adj[x]) {
                    if (y == pa) continue;
                    self(self, y, x);
                }
            };
            long long cur = 0;
            for (int y : adj[i]) {
                cnt = 0;
                dfs(dfs, y, -1);
                ans += cur * cnt;
                cur += cnt;
            }
            ans += cur;
        }
        return ans;
    }
};
