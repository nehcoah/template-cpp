class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0, tot = 0;
        for (int x : nums) {
            tot ^= x;
        }
        for (int i = 30; i >= 0; i--) {
            if ((tot >> i & 1) != (k >> i & 1)) ans++;
        }
        return ans;
    }
};
