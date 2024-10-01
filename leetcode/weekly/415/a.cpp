class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x] += 1;
        }
        vector<int> ans;
        for (auto [k, v] : mp) {
            if (v == 2) ans.push_back(k);
        }
        return ans;
    }
};
