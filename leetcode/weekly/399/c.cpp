class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> mp1, mp2;
        for (int x : nums1) {
            if (x % k == 0) mp1[x / k] += 1;
        }
        for (int x : nums2) {
            mp2[x] += 1;
        }
        long long ans = 0;
        for (auto [x, v] : mp1) {
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    if (mp2.count(i)) ans += 1ll * v * mp2[i];
                    if (i * i != x && mp2.count(x / i)) ans += 1ll * v * mp2[x / i];
                }
            }
        }
        return ans;
    }
};
