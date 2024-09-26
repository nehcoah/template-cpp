class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        const int mod = 1e9 + 7;
        int n = nums.size();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();
        vector<long long> info(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            pq.emplace(nums[i], i);
            info[i] = nums[i];
        }
        while (k--) {
            auto [x, i] = pq.top(); pq.pop();
            x *= multiplier; pq.emplace(x, i);
            info[i] = x % mod;
            if (i == mx) break;
        }
        
        auto power = [&](long long a, long long b) {
            long long ans = 1;
            for (; b; b /= 2) {
                if (b & 1) ans = ans * a % mod;
                a = a * a % mod;
            }
            return ans;
        };
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            auto [_, idx] = pq.top(); pq.pop();
            ans[idx] = (info[idx] * power(multiplier, k / n + (i < k % n ? 1 : 0))) % mod;
        }
        return ans;
    }
};
