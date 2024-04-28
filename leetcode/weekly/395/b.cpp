class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums2.begin(), nums2.end());
        
        auto check = [&](int i, int j) -> int {
            vector<int> cur;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                cur.push_back(nums1[k]);
            }
            sort(cur.begin(), cur.end());
            int x = nums2[0] - cur[0];
            for (int k = 0; k < cur.size(); k++) {
                if (cur[k] + x != nums2[k]) return 1e9;
            }
            return x;
        };
        
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = min(ans, check(i, j));
            }
        }
        return ans;
    }
};
