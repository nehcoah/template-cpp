class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        auto check = [&](vector<int> cur) {
            unordered_map<int, int> cnt;
            for (int x : cur) {
                cnt[x] += 1;
            }
            int ans = 0;
            for (int i = 0; i < x; i++) {
                int k = 0, v = 0;
                for (auto [K, V] : cnt) {
                    if (V > v || V == v && K > k) {
                        k = K, v = V;
                    }
                }
                ans += k * v;
                cnt.erase(k);
            }
            return ans;
        };

        vector<int> ans;
        for (int i = 0; i + k <= nums.size(); i++) {
            ans.push_back(check(vector(nums.begin() + i, nums.begin() + i + k)));
        }
        return ans;
    }
};
