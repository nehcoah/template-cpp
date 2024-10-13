class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            if (x == 2) ans.push_back(-1);
            else {
                int i = 0;
                while (x >> i & 1) i += 1;
                x ^= 1 << (i - 1);
                ans.push_back(x);
            }
        }
        return ans;
    }
};
