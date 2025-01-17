class Solution {
public:
    int minimumLength(string s) {
        // N + 26
        int freq[26] = {0}; 
        // Array to store the frequency of each character
        int n = s.length();
        
        // Count the frequency of each character in the string
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        
        int count = 0;
        // Calculate the minimum length
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (freq[i] % 2 == 0) {
                    count += 2;
                } else {
                    count += 1;
                }
            }
        }
        return count;
    }
};
