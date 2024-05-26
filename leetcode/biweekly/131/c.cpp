class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> btoc, ctoc;
        vector<int> ans;
        for (auto &q : queries) {
            int x = q[0], y = q[1];
            if (btoc.count(x)) {
                ctoc[btoc[x]] -= 1;
                if (ctoc[btoc[x]] == 0) ctoc.erase(btoc[x]);
                ctoc[y] += 1;
                btoc[x] = y;
            } else {
                ctoc[y] += 1;
                btoc[x] = y;
            }
            ans.push_back(ctoc.size());
        }
        return ans;
    }
};
