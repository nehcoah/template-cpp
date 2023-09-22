// https://leetcode.cn/problems/row-with-maximum-ones/

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int count[n];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; i++){
            for (int x : mat[i]) if(x == 1) count[i]++;
        }
        int idx = max_element(count, count + n) - count;
        return {idx, count[idx]};
    }
};
