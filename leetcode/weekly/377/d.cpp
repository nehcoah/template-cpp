// O(n^2 + m^3 + mn)
// 1e6的复杂度，就是常数应该打了一点，用stl一直在tle

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> mp;
        long long inf = 1e16;
        int cnt = 0;
        for (string &s : original) {
            if (mp.count(s) == 0) mp[s] = cnt++;
        }
        for (string &s : changed) {
            if (mp.count(s) == 0) mp[s] = cnt++;
        }
        long long w[cnt][cnt];
        for (int i = 0; i < cnt; i++) for (int j = 0; j < cnt; j++) w[i][j] = inf;
        // vector<vector<long long>> w(cnt, vector<long long>(cnt, inf));
        for (int i = 0; i < original.size(); i++) {
            w[mp[original[i]]][mp[changed[i]]] = min(w[mp[original[i]]][mp[changed[i]]], (long long) cost[i]);
        }
        for (int p = 0; p < cnt; p++) {
            for (int i = 0; i < cnt; i++) {
                for (int j = 0; j < cnt; j++) {
                    w[i][j] = min(w[i][j], w[i][p] + w[p][j]);
                }
            }
        }
        
        int n = source.size();
        // vector<vector<int>> S(n, vector<int>(n, -1)), T(n, vector<int>(n, -1));
        int S[n][n], T[n][n];
        memset(S, -1, sizeof(S));
        memset(T, -1, sizeof(T));
//         for (auto it : mp) {
//             long long base = 131, mod = 998244353, P = 1, cur = 0;
//             int len = it.first.size();
//             for (char c : it.first) {
//                 cur = (cur * base + c - 'a') % mod;
//                 P = P * base % mod;
//             }
            
//             auto check = [&](string &t, auto cur_hash) {
//                 long long hash = 0;
//                 for (int i = 0; i < len; i++) {
//                     hash = (hash * base + (t[i] - 'a')) % mod;
//                 }
//                 if (hash == cur) cur_hash[0][len - 1] = it.second;
//                 for (int i = len; i < n; i++) {
//                     hash = (hash * base + (t[i] - 'a')) % mod;
//                     hash = ((hash - P * (t[i - len] - 'a')) % mod + mod) % mod;
//                     if (hash == cur) cur_hash[i - len + 1][i] = it.second;
//                 }
//             };
//             check(source, S);
//             check(target, T);
//         }
        for (auto it : mp) {
            long long base = 131, mod = 998244353, P = 1, cur = 0;
            int len = it.first.size();
            for (char c : it.first) {
                cur = (cur * base + c - 'a') % mod;
                P = P * base % mod;
            }
            
            long long hash = 0;
            for (int i = 0; i < len; i++) {
                hash = (hash * base + (source[i] - 'a')) % mod;
            }
            if (hash == cur) S[0][len - 1] = it.second;
            for (int i = len; i < n; i++) {
                hash = (hash * base + (source[i] - 'a')) % mod;
                hash = ((hash - P * (source[i - len] - 'a')) % mod + mod) % mod;
                if (hash == cur) S[i - len + 1][i] = it.second;
            }
        }
        for (auto it : mp) {
            long long base = 131, mod = 998244353, P = 1, cur = 0;
            int len = it.first.size();
            for (char c : it.first) {
                cur = (cur * base + c - 'a') % mod;
                P = P * base % mod;
            }
            
            long long hash = 0;
            for (int i = 0; i < len; i++) {
                hash = (hash * base + (target[i] - 'a')) % mod;
            }
            if (hash == cur) T[0][len - 1] = it.second;
            for (int i = len; i < n; i++) {
                hash = (hash * base + (target[i] - 'a')) % mod;
                hash = ((hash - P * (target[i - len] - 'a')) % mod + mod) % mod;
                if (hash == cur) T[i - len + 1][i] = it.second;
            }
        }
        
        // vector<long long> f(n + 1, inf);
        long long f[n + 1];
        for (int i = 1; i < n + 1; i++) f[i] = inf;
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] == target[i]) f[i + 1] = f[i];
            for (int j = i; j >= 0; j--) {
                int x = S[j][i], y = T[j][i];
                if (x == -1 || y == -1) continue;
                if (w[x][y] == inf) continue;
                f[i + 1] = min(f[i + 1], f[j] + w[x][y]);
            }
        }
        return f[n] == inf ? -1 : f[n];
    }
};
