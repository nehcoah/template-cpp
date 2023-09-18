// https://leetcode.cn/problems/find-the-losers-of-the-circular-game/

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> nums(n);
        nums[0] = 1;
        int cur = k, pre = 0;
        while (true) {
            int nxt = (pre + cur) % n;
            if (nums[nxt] == 1) break;
            nums[nxt] = 1;
            pre = nxt;
            cur += k;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) ans.push_back(i + 1);
        }
        return ans;
    }
};
