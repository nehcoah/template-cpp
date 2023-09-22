// https://leetcode.cn/problems/find-the-score-of-all-prefixes-of-an-array/

using ll = long long;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<ll> ret;
        int mx = 0;
        ll cur = 0, ans = 0;
        for (int x : nums){
            mx = max(mx, x);
            cur += x + mx;
            ret.push_back(cur);
        }
        return ret;
    }
};
