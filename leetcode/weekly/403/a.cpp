class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double mn = 100;
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            mn = min(mn, 1. * (nums[i] + nums[j]) / 2);
        }
        return mn;
    }
};
