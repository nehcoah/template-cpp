class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        long long tot = accumulate(nums.begin(), nums.end(), 0ll) + n;
        vector<int> pre(n, -1);
        for (int i = m - 1; i >= 0; i--) {
            pre[changeIndices[i] - 1] = i;
        }

        auto check = [&](int x) {
            int cnt = 0;
            long long sum = tot;
            priority_queue<int, vector<int>, greater<>> pq;
            for (int i = x; i >= 0; i--) {
                int id = changeIndices[i] - 1, v = nums[id];
                if (v <= 1 || i != pre[id]) {
                    cnt += 1;
                    continue;
                }
                if (cnt == 0) {
                    if (pq.empty() || v <= pq.top()) {
                        cnt += 1;
                        continue;
                    }
                    sum += 1 + pq.top();
                    pq.pop();
                    cnt += 2;
                }
                sum -= v + 1;
                cnt -= 1;
                pq.push(v);
            }
            return cnt >= sum;
        };

        int l = 0, r = m;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l == m ? -1 : l + 1;
    }
};
