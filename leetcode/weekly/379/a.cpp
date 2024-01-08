class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int x = max_element(dimensions.begin(), dimensions.end(), [&](auto &a, auto &b) {
            int la = a[0] * a[0] + a[1] * a[1];
            int lb = b[0] * b[0] + b[1] * b[1];
            return la == lb ? a[0] * a[1] < b[0] * b[1] : la < lb;
        }) - dimensions.begin();
        return dimensions[x][0] * dimensions[x][1];
    }
};
