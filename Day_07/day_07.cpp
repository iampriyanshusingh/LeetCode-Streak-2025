class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);
        for (string word : words2) { // M
            vector<int> temp = getFreq(word); // p
            for (int i = 0; i < 26; i++) { // 26
                freq[i] = max(freq[i], temp[i]);
            }
        }
        vector<string> res;
        for (string word : words1) { // n
            vector<int> temp = getFreq(word); // p
            bool flag = true;
            for (int i = 0; i < 26; i++) { // 26
                if (freq[i] > temp[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word);
            }
        }
        return res;
    }
    
    vector<int> getFreq(string word) {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.length(); i++) {
            freq[word[i] - 'a']++;
        }
        return freq;
    }
};
