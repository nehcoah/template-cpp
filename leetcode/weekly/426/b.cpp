class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0, ans = -1e9;
        for (int x : nums) {
            mp[x] += 1;
            sum += x;
        }
        for (int x : nums) {
            int cur = sum - x;
            if (cur % 2 == 0) {
                if (mp.contains(cur / 2) && (x != cur / 2 || mp[cur / 2] > 1)) {
                    ans = max(ans, x);
                }
            }
        }
        return ans;
    }
};
