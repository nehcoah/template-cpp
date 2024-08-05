class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(i);
        }
        
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            auto it = st.lower_bound(l);
            if (it != st.end() && *it < r) {
                if (*it == l) it++;
                while (*it < r) {
                    it = st.erase(it);
                }
            }
            ans.push_back(st.size() - 1);
        }
        return ans;
    }
};
