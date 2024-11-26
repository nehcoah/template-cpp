class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(queries.begin(), queries.end());
        vector<int> d(n + 1);
        int id = 0, ans = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            if (i > 0) d[i] += d[i - 1];
            while (id < queries.size() && queries[id][0] <= i) {
                pq.push(queries[id][1]);
                id += 1;
            }
            if (nums[i] - d[i] <= 0) continue;
            if (nums[i] - d[i] > pq.size()) return -1;
            while (!pq.empty() && nums[i] - d[i] > 0) {
                int r = pq.top(); pq.pop();
                if (r < i) break;
                d[i] += 1, d[r + 1] -= 1;
                ans += 1;
            }
            if (nums[i] - d[i] > 0) return -1;
        }
        return queries.size() - ans;
    }
};
