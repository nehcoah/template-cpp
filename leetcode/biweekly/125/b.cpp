class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        for (int x : nums) {
            pq.push(x);
        }
        int ans = 0;
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            if (x >= k) break;
            auto y = pq.top(); pq.pop();
            pq.push(x * 2 + y);
            ans += 1;
        }
        return ans;
    }
};
