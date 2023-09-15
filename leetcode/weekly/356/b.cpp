// 2799
// https://leetcode.cn/problems/count-complete-subarrays-in-an-array/
// slide window

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s{nums.begin(), nums.end()};
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            mp[nums[r]]++;
            while (mp.size() == s.size()) {
                if (--mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            ans += l;
        }
        return ans;
    }
};
