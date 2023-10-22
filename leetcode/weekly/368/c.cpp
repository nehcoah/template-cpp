class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = 0;
        for (int x : nums) {
            mp[x]++;
            mx = max(mp[x], mx);
        }
        int ans = 1e9 + 1;
        auto check = [&](int t) -> int {
            int res = 0;
            for (auto [k, x] : mp) {
                if (x == t || x == t + 1) {
                    res++;
                    continue;
                }
                int d = x / (t + 1);
                int m = x % (t + 1);
                if (m == 0) res += d;
                else if (d + m < t) return 1e9;
                else res += d + 1;
            }
            return res;
        };
        for (int i = mx; i > 0; i--) {
            ans = min(ans, check(i));
        }
        return ans;
    }
};
