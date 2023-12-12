class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            int cur = 1;
            for (int j = 0; j < b; j++) {
                cur = cur * a % 10;
            }
            int t = 1;
            for (int j = 0; j < c; j++) {
                t = t * cur % m;
            }
            if (t == target) ans.push_back(i);
        }
        return ans;
    }
};
