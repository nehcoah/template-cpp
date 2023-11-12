class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size(), n = values[0].size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < m; i++) {
            pq.emplace(-values[i].back(), i);
            values[i].pop_back();
        }
        long long ans = 0, cnt = 1;
        while (!pq.empty()) {
            auto [x, i] = pq.top(); pq.pop();
            ans += -x * cnt++;
            if (!values[i].empty()) {
                pq.emplace(-values[i].back(), i);
                values[i].pop_back();
            }
        }
        return ans;
    }
};
