class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        multiset<int> st;
        vector<int> ans;
        for (auto &q : queries) {
            int x = abs(q[0]) + abs(q[1]);
            st.insert(x);
            if (st.size() > k) st.erase(prev(st.end()));
            if (st.size() == k) ans.push_back(*st.rbegin());
            else ans.push_back(-1);
        }
        return ans;
    }
};
