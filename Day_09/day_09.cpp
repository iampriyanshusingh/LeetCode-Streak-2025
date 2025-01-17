class Solution {
public:
    int maxScore(string s) {
        // Find all the ones
        int ones = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones++;
        }

        // Find max partition
        int res = 0;
        int zeros = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') zeros++;
            else ones--;
            res = max(res, ones + zeros);
        }
        return res;
    }
};
