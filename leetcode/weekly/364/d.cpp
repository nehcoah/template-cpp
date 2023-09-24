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
        
        vector<int> sz(n), nodes;
        auto dfs = [&](auto self, int x, int pa) -> void {
            if (isPrime[x + 1]) return;
            nodes.push_back(x);
            for (int y : adj[x]) {
                if (y == pa) continue;
                self(self, y, x);
            }
        };

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (!isPrime[i + 1]) continue;
            long long cur = 0;
            for (int y : adj[i]) {
                if (isPrime[y + 1]) continue;
                if (sz[y] == 0) {
                    nodes.clear();
                    dfs(dfs, y, -1);
                    for (int z : nodes) sz[z] = nodes.size();
                }
                ans += cur * sz[y];
                cur += sz[y];
            }
            ans += cur;
        }
        return ans;
    }
};

// int N = 1e5 + 1;
// vector<bool> isPrime;
// auto init = [](){
//     isPrime.resize(N, true);
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i < N; i++){
//         if (isPrime[i]){
//             for (int j = i * 2; j < N; j += i) {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     return 0;
// }();

// struct UnionFind {
//     vector<int> parent, size;
//     int cnt;

//     UnionFind(int n) {
//         parent.resize(n);
//         size.resize(n, 1);
//         cnt = n;
//         iota(parent.begin(), parent.end(), 0);
//     }

//     int find(int x){
//         if (parent[x] != x) parent[x] = find(parent[x]);
//         return parent[x];
//     }

//     bool merge(int x, int y){
//         x = find(x), y = find(y);
//         if (x == y) return false;
//         if (size[x] > size[y]) {
//             parent[y] = x;
//             size[x] += size[y];
//         } else {
//             parent[x] = y;
//             size[y] += size[x];
//         }
//         --cnt;
//         return true;
//     }

//     bool is_connected(int x, int y) {
//         return find(x) == find(y);
//     }
// };

// class Solution {
// public:
//     long long countPaths(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         for (auto &e : edges) {
//             adj[e[0] - 1].push_back(e[1] - 1);
//             adj[e[1] - 1].push_back(e[0] - 1);
//         }
        
//         UnionFind uf(n);
//         auto dfs = [&](auto self, int x, int pa) -> void {
//             if (!isPrime[x + 1]) {
//                 for (int y : adj[x]) {
//                     if (y == pa) continue;
//                     if (!isPrime[y + 1]) uf.merge(x, y);
//                 }
//             }
//             for (int y : adj[x]) {
//                 if (y == pa) continue;
//                 self(self, y, x);
//             }
//         };
//         dfs(dfs, 0, -1);

//         long long ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (isPrime[i + 1]) {
//                 int sum = 0;
//                 for (int x : adj[i]) {
//                     if (isPrime[x + 1]) continue;
//                     int cur = uf.size[uf.find(x)];
//                     ans += (long long)cur * sum;
//                     sum += cur;
//                 }
//                 ans += sum;
//             }
//         }
//         return ans;
//     }
// };
