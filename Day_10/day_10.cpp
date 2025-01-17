class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = isVowel(words[0]);

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + isVowel(words[i]);
        }

        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int res = prefixSum[r];
            if (l != 0) {
                res -= prefixSum[l - 1];
            }
            ans[i] = res;
        }

        return ans;
    }
}