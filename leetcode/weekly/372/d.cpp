class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), q = queries.size();
        for (int i = 0; i < q; i++) if (queries[i][0] > queries[i][1]) swap(queries[i][0], queries[i][1]);
        vector<int> idx(n), qidx(q), ans(q);
        set<int> st;
        iota(idx.begin(), idx.end(), 0);
        iota(qidx.begin(), qidx.end(), 0);
        ranges::sort(idx, [&](int a, int b) {return heights[a] > heights[b];} );
        ranges::sort(qidx, [&](int a, int b) {return heights[queries[a][0]] > heights[queries[b][0]];} );
        
        for (int qi = 0, i = 0; qi < q; qi++) {
            int a = queries[qidx[qi]][0], b = queries[qidx[qi]][1];
            if (a == b) ans[qidx[qi]] = a;
            else if (heights[a] < heights[b]) ans[qidx[qi]] = b;
            else {
                while (i < n && heights[idx[i]] > heights[a]) st.insert(idx[i]), i++;
                auto it = st.upper_bound(b);
                if (it == st.end()) ans[qidx[qi]] = -1;
                else ans[qidx[qi]] = *it;
            }
            
        }
        return ans;
    }
};
