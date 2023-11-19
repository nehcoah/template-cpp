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
