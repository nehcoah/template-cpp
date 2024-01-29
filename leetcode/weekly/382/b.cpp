class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 1;
        map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        for (auto [k, v] : mp) {
            if (k == 1 || v == 1) continue;
            int cnt = 1;
            for (long long x = 1ll * k * k; x <= 1e9; x = x * x) {
                if (mp[x] == 0) break;
                cnt += 2;
                if (mp[x] == 1) break;
            }
            ans = max(ans, cnt);
        }
        ans = max(ans, mp[1] % 2 ? mp[1] : mp[1] - 1);
        return ans;
    }
};
