class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < k - 1; i++) {
            if (nums[i + 1] - nums[i] != 1) cnt += 1;
        }
        if (cnt == 0) ans.push_back(nums[k - 1]);
        else ans.push_back(-1);
        for (int i = k; i < n; i++) {
            if (nums[i - k + 1] - nums[i - k] != 1) cnt -= 1;
            if (nums[i] - nums[i - 1] != 1) cnt += 1;
            if (cnt == 0) ans.push_back(nums[i]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
