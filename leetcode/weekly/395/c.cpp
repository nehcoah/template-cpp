class Solution {
public:
    long long minEnd(int n, int x) {
        n -= 1;
        long long ans = x;
        for (int i = 0, j = 0; i <= 30; i++) {
            while (ans >> j & 1) j += 1;
            if (n >> i & 1) ans |= 1ll << j;
            j += 1;
        }
        return ans;
    }
};
