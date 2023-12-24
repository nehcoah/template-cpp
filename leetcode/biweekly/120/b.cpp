class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (sum[i] > nums[i]) return sum[i + 1];
        }
        return -1;
    }
};
