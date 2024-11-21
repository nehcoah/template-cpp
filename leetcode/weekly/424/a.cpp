class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](int x, int d) {
            auto a = nums;
            while (true) {
                while (x >= 0 && x < n && a[x] == 0) {
                    x += d;
                }
                if (x < 0 || x >= n) break;
                a[x] -= 1;
                d = -d;
                x += d;
            }
            return count(a.begin(), a.end(), 0) == a.size();
        };

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) continue;
            ans += check(i, 1);
            ans += check(i, -1);
        }
        return ans;
    }
};
