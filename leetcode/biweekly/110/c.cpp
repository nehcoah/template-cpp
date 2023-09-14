// 2808
// https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array/
// 

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = n + 1;
        for (auto& [k, v] : mp) {
            int cur = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                cur = max(cur, (v[i + 1] - v[i]) / 2);
            }
            cur = max(cur, (n - v.back() + v[0]) / 2);
            ans = min(cur, ans);
            // cout << cur << endl;
        }
        return ans;
    }
};
