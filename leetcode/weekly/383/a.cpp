class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int sum = 0, ans = 0;
        for (int x : nums) {
            sum += x;
            if (sum == 0) ans++;
        }
        return ans;
    }
};
