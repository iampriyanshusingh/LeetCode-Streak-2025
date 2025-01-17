class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (n < k) return false;
        if (n == k) return true;
        // Find frequency
        int count[26] = {0};
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        int c = 0;
        // Find odd count
        for (int i = 0; i < 26; i++) {
            if (count[i] & 1) c++;
        }
        return (c <= k);
    }
};