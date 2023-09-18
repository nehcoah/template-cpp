// https://leetcode.cn/problems/maximum-sum-queries/

class SegmentTree_dynamic{
    int l, r;
    int mx = -1;
    SegmentTree_dynamic *left, *right;
public:
    SegmentTree_dynamic(int l, int r): l(l), r(r), left(nullptr), right(nullptr) {}

    void update(int index, int val){
        if (l == r){
            mx = max(mx, val);
            return;
        }
        int mid = l + r >> 1;
        if (left == nullptr) {
            left = new SegmentTree_dynamic(l, mid);
            right = new SegmentTree_dynamic(mid + 1, r);
        }
        if (index <= mid) left->update(index, val);
        else right->update(index, val);
        mx = max(left->mx, right->mx);
    }

    int query(int ql, int qr){
        if (ql <= l && r <= qr){
            return mx;
        }
        int mid = l + r >> 1, mx_ = -1;
        if (left == nullptr) {
            left = new SegmentTree_dynamic(l, mid);
            right = new SegmentTree_dynamic(mid + 1, r);
        }
        if (ql <= mid) mx_ = max(mx_, left->query(ql, qr));
        if (mid < qr) mx_ = max(mx_, right->query(ql, qr));
        return mx_;
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size(), qn = queries.size(), i = 0, mx = *max_element(nums2.begin(), nums2.end());
        vector<int> idx(n), qidx(qn);
        iota(idx.begin(), idx.end(), 0);
        iota(qidx.begin(), qidx.end(), 0);
        sort(idx.begin(), idx.end(), [&](auto a, auto b){
            return nums1[a] > nums1[b];
        });
        sort(qidx.begin(), qidx.end(), [&](auto a, auto b){
            return queries[a][0] > queries[b][0];
        });
        auto st = new SegmentTree_dynamic(0, mx);
        vector<int> ans(qn);
        for (int qi : qidx) {
            int ax = queries[qi][0], ay = queries[qi][1];
            while (i < n && nums1[idx[i]] >= ax) st->update(nums2[idx[i]], nums1[idx[i]] + nums2[idx[i]]), i++;
            ans[qi] = st->query(ay, mx);
        }
        return ans;
    }
};
