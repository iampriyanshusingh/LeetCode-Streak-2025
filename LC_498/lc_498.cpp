class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> v;
        int flag = 0;

        // Traverse diagonals starting from each row of first column
        for (int i = 0; i < m; i++) {
            int j = i;
            int k = 0;
            vector<int> temp;
            while (j >= 0 && k < n) {
                temp.push_back(mat[j][k]);
                j--;
                k++;
            }
            if (flag % 2 == 0)
                v.push_back(temp);
            else {
                reverse(temp.begin(), temp.end());
                v.push_back(temp);
            }
            flag++;
        }

        // Adjust flag for diagonals starting from columns
        if (m % 2 == 0)
            flag = 0;
        else
            flag = 1;

        // Traverse diagonals starting from columns of last row
        for (int i = 0; i < n - 1; i++) {
            int j = m - 1;
            int k = i + 1;
            vector<int> temp;
            while (j >= 0 && k < n) {
                temp.push_back(mat[j][k]);
                j--;
                k++;
            }
            if (flag % 2 == 0)
                v.push_back(temp);
            else {
                reverse(temp.begin(), temp.end());
                v.push_back(temp);
            }
            flag++;
        }

        // Merge all diagonals into single result
        vector<int> ans;
        for (auto& it : v) {
            for (auto& val : it) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};