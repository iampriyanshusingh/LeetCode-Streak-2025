class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(); // rows
        int m = mat[0].size(); // cols
        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);
        // num -> (r, c)
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[mat[i][j]] = {i, j};
            }
        }
        int totalCells = n * m;
        for (int i = 0; i < totalCells; i++) {
            auto cell = map[arr[i]];
            rowCount[cell.first]++;
            colCount[cell.second]++;
            if (rowCount[cell.first] == m || colCount[cell.second] == n) {
                return i;
            }
        }
        return -1;
    }
};
