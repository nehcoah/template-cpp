class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        auto check = [&]() -> int {
            int cur = 0;
            for (int i = 0; i < n - 1; i++) {
                if (nums1[i] > nums1.back() || nums2[i] > nums2.back()) {
                    if (nums1[i] <= nums2.back() && nums2[i] <= nums1.back()) cur++;
                    else return 1e5;
                }
            }
            return cur;
        };
        
        int ans = check();
        swap(nums1.back(), nums2.back());
        ans = min(ans, check() + 1);
        return ans > n ? -1 : ans;
    }
};
