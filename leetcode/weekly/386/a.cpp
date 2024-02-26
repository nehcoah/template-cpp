class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(101);
        for (int x : nums) {
            cnt[x]++;
        }
        int c = 0;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] > 2) return false;
            else if (cnt[i] == 2) c++;
        }
        return c <= n / 2;
    }
};
