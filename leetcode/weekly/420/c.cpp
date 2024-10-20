vector<int> p, mf;

auto init = []() {
    p.resize(1e6 + 1, 1);
    mf.resize(1e6 + 1, 1);
    for (int i = 2; i < p.size(); i++) {
        if (!p[i]) continue;
        for (int j = i + i; j < p.size(); j += i) {
            p[j] = 0;
            if (mf[j] == 1) mf[j] = j / i;
        }
    }
    return 0;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            while (nums[i] > nums[i + 1]) {
                if (mf[nums[i]] == 1) return -1;
                nums[i] /= mf[nums[i]];
                ans += 1;
            }
        }
        return ans;
    }
};
