class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        // f[i] -> i-th max len
        // lst[i] -> i-th min element satisfy f[i]
        // max j where sum[i] - sum[j] >= lst[j] --> f[i] = f[j] + 1
        // max j where sum[j] + lst[j] <= sum[i]
        
        int n = nums.size();
        vector<long long> sum(n + 1), f(n + 1), lst(n + 1);
        deque<int> dq{0};
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
        for (int i = 0; i < n; i++) {
            while (dq.size() > 1 && sum[dq[1]] + lst[dq[1]] <= sum[i + 1]) dq.pop_front();
            f[i + 1] = f[dq.front()] + 1;
            lst[i + 1] = sum[i + 1] - sum[dq.front()];
            while (!dq.empty() && lst[dq.back()] + sum[dq.back()] >= lst[i + 1] + sum[i + 1]) dq.pop_back();
            dq.push_back(i + 1);
        }
        
        return f[n];
    }
};

// class Solution {
// public:
//     int findMaximumLength(vector<int>& nums) {
//         // f[i] -> i-th max len
//         // lst[i] -> i-th min element satisfy f[i]
//         // max j where sum[i] - sum[j] >= lst[j] --> f[i] = f[j] + 1
//         // max j where sum[j] + lst[j] <= sum[i]
        
//         int n = nums.size();
//         vector<long long> sum(n + 1), f(n + 1), lst(n + 1), stk{0};
//         for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
//         for (int i = 0; i < n; i++) {
//             int l = 0, r = stk.size() - 1;
//             while (l < r) {
//                 int mid = (l + r + 1) >> 1;
//                 if (sum[stk[mid]] + lst[stk[mid]] <= sum[i + 1]) l = mid;
//                 else r = mid - 1;
//             }
//             f[i + 1] = f[stk[l]] + 1;
//             lst[i + 1] = sum[i + 1] - sum[stk[l]];
//             while (!stk.empty() && lst[stk.back()] + sum[stk.back()] >= lst[i + 1] + sum[i + 1]) stk.pop_back();
//             stk.push_back(i + 1);
//         }
        
//         return f[n];
//     }
// };
