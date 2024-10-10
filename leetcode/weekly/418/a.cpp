class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int ans = 0;
        for (int t = 0; t < 6; t++) {
            int cur = 0;
            for (int i = 0; i < 3; i++) {
                string s;
                int x = nums[i];
                while (x) {
                    s += char(x % 2 + '0');
                    x /= 2;
                }
                reverse(s.begin(), s.end());
                for (char c : s) {
                    cur *= 2;
                    cur += c - '0';
                }
            }
            ans = max(ans, cur);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
};
