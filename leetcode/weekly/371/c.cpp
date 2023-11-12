class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        auto check = [&]() {
            int cur = 0;
            for (int i = 0; i < n - 1; i++) {
                if (nums1[i] > nums1.back() || nums2[i] > nums2.back()) {
                    if (nums1[i] <= nums2.back() && nums2[i] <= nums1.back()) cur++;
                    else return -2;
                }
            }
            return cur;
        };
        
        int ans1 = check();
        swap(nums1.back(), nums2.back());
        int ans2 = check() + 1;
        if (ans1 < 0 && ans2 < 0) return -1;
        else if (ans1 < 0) return ans2;
        else if (ans2 < 0) return ans1;
        else return min(ans1, ans2);
    }
};
