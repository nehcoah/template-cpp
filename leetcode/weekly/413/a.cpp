class Solution {
public:
    bool checkTwoChessboards(string s1, string s2) {
        int t1 = s1[0] - 'a' + s1[1] - '0';
        int t2 = s2[0] - 'a' + s2[1] - '0';
        return t1 % 2 == t2 % 2;
    }
};
