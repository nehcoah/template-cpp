// 2784
// https://leetcode.cn/problems/check-if-array-is-good/
// brute force

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> base(*max_element(nums.begin(), nums.end()));
        for (int x : nums) base[x - 1]++;
        for (int i = 0; i < base.size() - 1; i++) {
            if (base[i] != 1) return false;
        }
        return base.back() == 2;
    }
};
