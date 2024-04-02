const int mod = 1e9 + 7;
using ll = long long;

ll power(ll a, ll b) {
    ll ans = 1;
    for (; b; b /= 2) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        unordered_map<int, unordered_map<int, ll>> mp, cur;
        mp[0] = {{0, 1}};
        auto merge = [&]() {
            for (auto &[k1, v1] : cur) {
                for (auto [k2, v2] : v1) {
                    mp[k1][k2] = (mp[k1][k2] + v2) % mod;
                }
            }
            cur.clear();
        };
        ll ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int t = k - nums[i];
            if (mp.count(t)) {
                for (auto [x, c] : mp[t]) {
                    ans = (ans + power(2, n - x - 1) * c) % mod;
                }
            }
            for (auto &[k1, v1] : mp) {
                for (auto [k2, v2] : v1) {
                    if (k1 + nums[i] <= k) cur[k1 + nums[i]][k2 + 1] = v2;
                }
            }
            merge();
        }
        return ans;
    }
};

class Solution {
public:
    int sumOfPower(vector<int> &nums, int k) {
        vector<long long> f(k + 1);
        f[0] = 1;
        for (int x : nums) {
            for (int j = k; j >= 0; j--) {
                f[j] = (f[j] * 2 + (j >= x ? f[j - x] : 0)) % 1'000'000'007;
            }
        }
        return f[k];
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/find-the-sum-of-the-power-of-all-subsequences/solutions/2691661/liang-chong-fang-fa-er-wei-yi-wei-0-1-be-2e47/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
