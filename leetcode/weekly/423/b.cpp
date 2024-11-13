class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> f;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j + 1 < n && nums[j + 1] > nums[j]) {
                j += 1;
            }
            f.push_back(j - i + 1);
            i = j + 1;
        }

        int ans = 0;
        for (int i = 0; i < f.size(); i++) {
            ans = max(ans, f[i] / 2);
            if (i < f.size() - 1) {
                ans = max(ans, min(f[i], f[i + 1]));
            }
        }
        return ans;
    }
};
