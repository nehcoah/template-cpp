class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        auto c = [&](int n) -> long long {
            if (n < 0) return 0LL;
            return (long long) n * (n - 1) / 2;
        };
        return c(n + 2) - 3 * c(n - limit + 1) + 3 * c(n - 2 * limit) - c(n - 3 * limit - 1);
    }
};

// class Solution {
// public:
//     long long distributeCandies(int n, int limit) {
//         long long ans = 0;
//         if (limit * 3 < n) return ans;
//         for (int x = 0; x <= n && x <= limit; x++) {
//             int cur = n - x;
//             ans += max(0, cur <= limit ? cur + 1 : cur + 1 - 2 * (cur - limit));
//         }
//         return ans;
//     }
// };
