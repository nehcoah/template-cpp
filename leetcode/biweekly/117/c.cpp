class Solution {
public:
    int stringCount(int n) {
        const int mod = 1e9 + 7;
        auto power = [&](long long a, long long b) -> long long {
            long long ans = 1;
            for (; b; b /= 2) {
                if (b & 1) ans = ans * a % mod;
                a = a * a % mod;
            }
            return ans;
        };
        long long ans = power(26, n) - power(25, n - 1) * (n + 75) + power(24, n - 1) * (72 + 2 * n) - power(23, n - 1) * (23 + n);
        return (ans % mod + mod) % mod;
    }
};

// class Solution {
// public:
//     int stringCount(int n) {
//         const int mod = 1e9 + 7;
        
//         long long f[n + 1][2][3][2];
//         memset(f, 0, sizeof(f));
//         f[0][0][0][0] = 1;
//         for (int i = 0; i < n; i++) {
//             for (int l = 0; l < 2; l++) {
//                 for (int e = 0; e < 3; e++) {
//                     for (int t = 0; t < 2; t++) {
//                         f[i + 1][l][e][t] = (f[i + 1][l][e][t] + f[i][l][e][t] * 23 % mod) % mod;
//                         f[i + 1][min(l + 1, 1)][e][t] = (f[i + 1][min(l + 1, 1)][e][t] + f[i][l][e][t]) % mod;
//                         f[i + 1][l][min(e + 1, 2)][t] = (f[i + 1][l][min(e + 1, 2)][t] + f[i][l][e][t]) % mod;
//                         f[i + 1][l][e][min(t + 1, 1)] = (f[i + 1][l][e][min(t + 1, 1)] + f[i][l][e][t]) % mod;
//                     }
//                 }
//             }
//         }
//         return f[n][1][2][1];
//     }
// };

// class Solution {
// public:
//     int stringCount(int n) {
//         const int mod = 1e9 + 7;
        
//         int dp[n][1 << 4];
//         memset(dp, -1, sizeof(dp));
//         auto dfs = [&](auto self, int i, int mask) {
//             if (i == n) {
//                 return mask == (1 << 4) - 1 ? 1 : 0;
//             }
//             if (dp[i][mask] != -1) return dp[i][mask];
//             int ans = 0;
//             for (char c = 'a'; c <= 'z'; c++) {
//                 if (c == 'l') ans = (ans + self(self, i + 1, mask | (1 << 3))) % mod;
//                 else if (c == 't') ans = (ans + self(self, i + 1, mask | (1 << 2))) % mod;
//                 else if (c == 'e') {
//                     if (mask >> 1 & 1) ans = (ans + self(self, i + 1, mask | 1)) % mod;
//                     else ans = (ans + self(self, i + 1, mask | 2)) % mod;
//                 } else {
//                     ans = (ans + self(self, i + 1, mask)) % mod;
//                 }
//             }
//             return dp[i][mask] = ans;
//         };
//         return dfs(dfs, 0, 0);
//     }
// };
