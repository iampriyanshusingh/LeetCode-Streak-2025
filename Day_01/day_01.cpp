class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> firstOcc, lastOcc;
    int n = s.length();

    // Store first and last occurrence of each character
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (firstOcc.find(ch) == firstOcc.end()) {
            firstOcc[ch] = i;
        }
        lastOcc[ch] = i;
    }

    int count = 0;
    for (auto& entry : firstOcc) {
        char ch = entry.first;
        int first = entry.second;
        int last = lastOcc[ch];

        if (first == last) continue;

        unordered_set<char> uniqueChars;
        for (int i = first + 1; i < last; i++) {
            uniqueChars.insert(s[i]);
        }
        count += uniqueChars.size();
    }

    return count;
    }
};