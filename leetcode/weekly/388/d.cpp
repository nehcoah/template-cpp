class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        vector dp(n + 1, vector(k + 1, vector<ll>(2, -1e18)));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i + 1][j][0] = max({dp[i + 1][j][0], dp[i][j][0], dp[i][j][1]});
                dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1] + 1ll * (j & 1 ? 1 : -1) * nums[i] * (k - j + 1));
                if (j < k) dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], max(dp[i][j][0], dp[i][j][1]) + 1ll * (j & 1 ? -1 : 1) * nums[i] * (k - j));
            }
        }
        return max(dp[n][k][0], dp[n][k][1]);
    }
};

class Solution {
public:
    long long maximumStrength(vector<int> &nums, int k) {
        int n = nums.size();
        vector<long long> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }
        vector<vector<long long>> f(k + 1, vector<long long>(n + 1));
        for (int i = 1; i <= k; i++) {
            f[i][i - 1] = LLONG_MIN;
            long long mx = LLONG_MIN;
            int w = (k - i + 1) * (i % 2 ? 1 : -1);
            for (int j = i; j <= n - k + i; j++) { // j 的上下界是因为其它子数组至少要选一个数
                mx = max(mx, f[i - 1][j - 1] - s[j - 1] * w);
                f[i][j] = max(f[i][j - 1], s[j] * w + mx);
            }
        }
        return f[k][n];
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/maximum-strength-of-k-disjoint-subarrays/solutions/2678061/qian-zhui-he-hua-fen-xing-dpshi-zi-bian-ap5z5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
