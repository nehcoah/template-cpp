class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> cnt(51);
        for (int x : nums) {
            cnt[x] += 1;
        }
        int ans = 0;
        for (int i = 0; i < 51; i++) {
            if (cnt[i] == 2) ans ^= i;
        }
        return ans;
    }
};
