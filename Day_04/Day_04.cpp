class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || words[i].length() > words[j].length()) 
                    continue;

                if (isSubstring(words[i], words[j])) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }

    bool isSubstring(const string& sub, const string& word) {
        int n = word.length();
        int m = sub.length();
        for (int j = 0; j < n; j++) {
            bool isMatch = true;
            int k = j;
            int i = 0;
            while (i < m) {
                if (k >= word.length() || word[k] != sub[i]) {
                    isMatch = false;
                    break;
                }
                k++;
                i++;
            }
            if (isMatch) {
                return true;
            }
        }
        return false;
    }
};
