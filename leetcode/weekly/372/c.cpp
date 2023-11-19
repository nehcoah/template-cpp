class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int x = a >> i & 1, y = b >> i & 1;
            if (x == y && x == 0) {
                a |= 1LL << i;
                b |= 1LL << i;
            }
        }
        long long u = a, v = b;
        bool f = false;
        for (int i = 49; i >= 0; i--) {
            int x = a >> i & 1, y = b >> i & 1;
            if (x != y) {
                if (i < n) {
                    if (!f) f = true, b |= 1LL << i, a &= ~(1LL << i), v &= ~(1LL << i), u |= 1LL << i;
                    else a |= 1LL << i, b &= ~(1LL << i), u &= ~(1LL << i), v |= 1LL << i;
                } else f = true;
            }
        }
        __int128 ans1 = __int128(a) * b, ans2 = __int128(u) * v;
        if (ans1 > ans2) return ans1 % mod;
        else return ans2 % mod;
    }
};

// class Solution {
// public:
//     int maximumXorProduct(long long a, long long b, int n) {
//         const int mod = 1e9 + 7;
//         long long x = a & ~((1LL << n) - 1), y = b & ~((1LL << n) - 1);
//         for (int i = n - 1; i >= 0; i--) {
//             int u = a >> i & 1, v = b >> i & 1;
//             if (u == v) {
//                 x |= 1LL << i;
//                 y |= 1LL << i;
//             } else {
//                 if (x > y) y |= 1LL << i;
//                 else x |= 1LL << i;
//             }
//         }
//         return (x % mod) * (y % mod) % mod;
//     }
// };
