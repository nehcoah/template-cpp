class Solution {
public:
    int countPairs(vector<int>& nums) {
        auto check = [&](int x, int y) {
            if (x == y) return true;
            string sx = to_string(x);
            for (int i = 0; i < sx.size(); i++) {
                for (int j = i + 1; j < sx.size(); j++) {
                    auto nx = sx;
                    swap(nx[i], nx[j]);
                    if (y == stoi(nx)) return true;
                }
            }
            return false;
        };
        
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += check(nums[i], nums[j]) || check(nums[j], nums[i]);
            }
        }
        return ans;
    }
};
