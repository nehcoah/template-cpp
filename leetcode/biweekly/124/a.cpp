class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = 1, sum = nums[1] + nums[0], n = nums.size();
        for (int i = 2; i < n; i += 2) {
            if (nums[i] + nums[i + 1] == sum) ans++;
            else break;
        }
        return ans;
    }
};
