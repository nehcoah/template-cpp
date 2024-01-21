class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int x = *min_element(nums.begin(), nums.end());
        int cnt = 0;
        for (int y : nums) {
            if (x == y) cnt++;
        }
        if (cnt <= 2) return 1;
        for (int y : nums) {
            if (y != x && y % x != 0) return 1;
        }
        return (cnt + 1) / 2;
    }
};
