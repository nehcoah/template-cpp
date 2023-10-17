class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const int mod = 1e9 + 7;
        unordered_map<int, int> mp;
        int sum = 0;
        for (int x : nums) mp[x]++, sum += x;
        r = min(r, sum);
        vector<int> f(r + 1, 0);
        f[0] = mp[0] + 1;
        for (auto [x, cnt] : mp) {
            if (x == 0) continue;
            vector<int> tmp = f, window(x);
            for (int i = x; i <= r; i++) {
                int cur = i % x;
                window[cur] = (window[cur] + f[i -x]) % mod;
                int s = i - x * (cnt + 1);
                if (s >= 0) window[cur] = (window[cur] + mod - f[s]) % mod;
                tmp[i] = (tmp[i] + window[cur]) % mod;
            }
            f = move(tmp);
        }
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
};
