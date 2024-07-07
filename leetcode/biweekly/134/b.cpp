class Solution {
public:
    long long maximumPoints(vector<int>& a, int b) {
        int n = a.size();
        long long ans = 0, sum = 0;
        int mn = 1e9;
        for (int x : a) {
            mn = min(mn, x);
            sum += x;
        }
        if (b < mn) return 0;
        else return (sum + b - mn) / mn;
    }
};
