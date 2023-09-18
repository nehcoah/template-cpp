// https://leetcode.cn/problems/neighboring-bitwise-xor/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for (int x : derived) ans ^= x;
        return ans == 0;
    }
};
