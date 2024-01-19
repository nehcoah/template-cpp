// 2851
// https://leetcode.cn/problems/string-transformation/description/
// stringhash or kmp, matrix fast pow

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        const __int128 mod = (1ll << 61) - 1, base = rng() % (mod - 200) + 150;
        __int128 T = 0, S = 0, pw = 1;
        int n = t.size();
        s += s;
        s.pop_back();
        for (int i = 0; i < n; i++) {
            S = (S * base + s[i]) % mod;
            T = (T * base + t[i]) % mod;
            pw = pw * base % mod;
        }
        int cnt = S == T;
        vector<vector<ll>> ans{{S == T}, {S != T}};
        for (int i = n; i < s.size(); i++) {
            S = (S * base + s[i]) % mod;
            S = ((S - s[i - n] * pw) % mod + mod) % mod;
            cnt += S == T;
        }
        
        vector<vector<ll>> p{{cnt - 1, cnt}, {n - cnt, n - cnt - 1}};
        const int P = 1e9 + 7;

        auto mul = [](const auto &a, const auto &b) {
            int am = a.size(), an = a[0].size(), bm = b.size(), bn = b[0].size();
            assert(an == bm);
            vector<vector<ll>> ans(am, vector<ll>(bn));
            for (int i = 0; i < am; i++) {
                for (int j = 0; j < bn; j++) {
                    for (int k = 0; k < an; k++) {
                        ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % P;
                    }
                }
            }
            return ans;
        };

        auto power = [&](auto &a, ll b) {
            int m = a.size(), n = a[0].size();
            assert(m == n);
            vector<vector<ll>> ans(m, vector<ll>(n));
            for (int i = 0; i < n; i++) ans[i][i] = 1;
            for (; b; b /= 2) {
                if (b & 1) ans = mul(ans, a);
                a = mul(a, a);
            }
            return ans;
        };

        return mul(power(p, k), ans)[0][0];
    }
};

// class Solution {
// public:
//     int numberOfWays(string s, string t, long long k) {
//         int n = s.length();
//         int c = kmp_search(s + s.substr(0, n - 1), t);
//         vector<vector<long long>> m = {
//             {c - 1, c},
//             {n - c, n - 1 - c}
//         };
//         m = pow(m, k);
//         return m[0][s != t];
//     }

// private:
//     // KMP 模板
//     vector<int> calc_max_match(string s) {
//         vector<int> match(s.length());
//         int c = 0;
//         for (int i = 1; i < s.length(); i++) {
//             char v = s[i];
//             while (c && s[c] != v) {
//                 c = match[c - 1];
//             }
//             if (s[c] == v) {
//                 c++;
//             }
//             match[i] = c;
//         }
//         return match;
//     }

//     // KMP 模板
//     // 返回 text 中出现了多少次 pattern（允许 pattern 重叠）
//     int kmp_search(string text, string pattern) {
//         vector<int> match = calc_max_match(pattern);
//         int match_cnt = 0, c = 0;
//         for (int i = 0; i < text.length(); i++) {
//             char v = text[i];
//             while (c && pattern[c] != v) {
//                 c = match[c - 1];
//             }
//             if (pattern[c] == v) {
//                 c++;
//             }
//             if (c == pattern.length()) {
//                 match_cnt++;
//                 c = match[c - 1];
//             }
//         }
//         return match_cnt;
//     }

//     const long long MOD = 1e9 + 7;

//     // 矩阵乘法
//     vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b) {
//         vector<vector<long long>> c(2, vector<long long>(2));
//         for (int i = 0; i < 2; i++) {
//             for (int j = 0; j < 2; j++) {
//                 c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
//             }
//         }
//         return c;
//     }

//     // 矩阵快速幂
//     vector<vector<long long>> pow(vector<vector<long long>> &a, long long n) {
//         vector<vector<long long>> res = {{1, 0}, {0, 1}};
//         for (; n; n /= 2) {
//             if (n % 2) {
//                 res = multiply(res, a);
//             }
//             a = multiply(a, a);
//         }
//         return res;
//     }
// };

// // 作者：灵茶山艾府
// // 链接：https://leetcode.cn/problems/string-transformation/
// // 来源：力扣（LeetCode）
// // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
