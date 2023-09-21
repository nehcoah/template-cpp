// https://leetcode.cn/problems/make-array-empty/

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        long long ans = n;
        int id[n];
        iota(id, id + n, 0);
        sort(id, id + n, [&](int a, int b){return nums[a] < nums[b];});
        for (int i = 0; i < n - 1; i++) if (id[i] > id[i + 1]) ans += n - i - 1;
        return ans;
    }
};

// class Solution {
//     vector<int> tree;
//     void update(int pos, int val){
//         for (; pos < tree.size(); pos += pos & -pos) tree[pos] += val;
//     }
//     long long query(int pos){
//         long long ans = 0;
//         for (; pos; pos &= pos - 1) ans += tree[pos];
//         return ans;
//     }
// public:
//     long long countOperationsToEmptyArray(vector<int>& nums) {
//         int n = nums.size();
//         long long ans = n;
//         tree.resize(n + 1);
//         int idx[n];
//         iota(idx, idx + n, 0);
//         sort(idx, idx + n, [&](int a, int b){return nums[a] < nums[b];});
//         int pre = 1;
//         for (int id : idx){
//             id += 1;
//             if (id < pre) ans += id - query(id) + n - pre - query(n) + query(pre - 1);
//             else ans += id - pre - query(id) + query(pre - 1);
//             update(id, 1);
//             pre = id;
//         }
//         return ans;
//     }
// };
