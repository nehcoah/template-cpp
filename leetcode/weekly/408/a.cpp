class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0), cur = 0;
        for (int i = 0; i < n; i++) {
            auto s = to_string(nums[i]);
            if (s.size() == 1) cur += nums[i];
        }
        return sum != cur * 2;
    }
};
