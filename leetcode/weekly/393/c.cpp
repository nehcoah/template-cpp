class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto check = [&](long long x) {
            long long cnt = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                int lcm = 1;
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) {
                        lcm = std::lcm(lcm, coins[i]);
                    }
                }
                if (__builtin_popcount(mask) % 2) cnt += x / lcm;
                else cnt -= x / lcm;
            }
            return cnt;
        };
        
        long long l = 0, r = 4e18;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (check(mid) < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
