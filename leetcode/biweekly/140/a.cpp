class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for (int x : nums) {
            int cur = 0;
            while (x) {
                cur += x % 10;
                x /= 10;
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};
