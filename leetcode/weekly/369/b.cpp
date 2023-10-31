class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cnt1 = 0, cnt2 = 0;
        long long sum1 = 0, sum2 = 0;
        for (int x : nums1) {
            sum1 += x;
            if (x == 0) cnt1++;
        }
        for (int x : nums2) {
            sum2 += x;
            if (x == 0) cnt2++;
        }
        if (sum1 == sum2) {
            if (cnt1 == 0 && cnt2 == 0) return sum1;
            else if (cnt1 != 0 && cnt2 != 0) return sum1 + max(cnt1, cnt2);
            else return -1;
        } else {
            if (sum1 < sum2) {
                swap(sum1, sum2);
                swap(cnt1, cnt2);
            }
            if (cnt2 == 0) return -1;
            else if (cnt1 != 0) return max(sum1 + cnt1, sum2 + cnt2);
            else {
                if (sum2 + cnt2 > sum1) return -1;
                else return sum1;
            }
        }
    }
};
