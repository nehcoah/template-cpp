class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        map<int, int> d;
        for (int x : nums) {
            cnt[x] += 1;
            if (d.count(x) == 0) d[x] = 0;
            d[x - k] += 1;
            d[x + k + 1] -= 1;
        }

        int x = 0;
        int ans = 0;
        for (auto [k, v] : d) {
            x += v;
            ans = max(ans, min(x, cnt[k] + numOperations));
        }
        return ans;
    }
};
