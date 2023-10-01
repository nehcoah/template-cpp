class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        int ans = 0;
        for (auto [k, v] : mp) {
            if (v == 1) return -1;
            else {
                if (v % 3 == 0) ans += v / 3;
                else if (v % 3 == 1) ans += (v - 4) / 3 + 2;
                else ans += v / 3 + 1;
            }
        }
        return ans;
    }
};
