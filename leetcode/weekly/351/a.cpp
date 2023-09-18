// https://leetcode.cn/problems/number-of-beautiful-pairs/

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int x = to_string(nums[i])[0] - '0';
                int y = to_string(nums[j]).back() - '0';
                if (gcd(x, y) == 1) ans++;
            }
        }
        return ans;
    }
};
