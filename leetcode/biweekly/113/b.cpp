// https://leetcode.cn/problems/minimum-array-length-after-pair-removals/description/

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size(), pre = -1;
        priority_queue<int> pq;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) pq.push(i - pre), pre = i;
        }
        pq.push(n - pre - 1);
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            if (pq.empty()) return x;
            int y = pq.top(); pq.pop();
            if (--x > 0) pq.push(x);
            if (--y > 0) pq.push(y);
        }
        return 0;
    }
};
