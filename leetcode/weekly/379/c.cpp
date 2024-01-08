class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_set<int> st1{nums1.begin(), nums1.end()}, st2{nums2.begin(), nums2.end()};
        if (st1.size() <= n1 / 2 && st2.size() <= n2 / 2) {
            st1.insert(st2.begin(), st2.end());
            return st1.size();
        } else if (st1.size() > n1 / 2 && st2.size() > n2 / 2) {
            st1.insert(st2.begin(), st2.end());
            return min((int)st1.size(), (n1 + n2) / 2);
        } else {
            if (st2.size() > n2 / 2) {
                swap(st1, st2);
                swap(n1, n2);
            }
            st1.insert(st2.begin(), st2.end());
            return min((int)st1.size(), (int)st2.size() + n1 / 2);
        }
    }
};
