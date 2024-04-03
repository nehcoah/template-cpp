class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        auto check = [&](int s, int e) {
            int ans = 0;
            for (int i = s; i <= e; i++) {
                ans |= nums[i];
            }
            return ans >= k;
        };
        
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(i, j) && (ans == -1 || ans > j - i + 1)) ans = j - i + 1;
            }
        }
        return ans;
    }
};
