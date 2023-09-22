// https://leetcode.cn/problems/find-the-maximum-divisibility-score/

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int score = -1, ans = -1;
        sort(divisors.begin(), divisors.end());
        divisors.erase(unique(divisors.begin(), divisors.end()), divisors.end());
        for (int d : divisors){
            int cur = 0;
            for (int n : nums) if (n % d == 0) cur++;
            if (cur > score){
                score = cur;
                ans = d;
            }
        }
        return ans;
    }
};
