class Solution {
public:
    int minimumSum(vector<vector<int>>& A) {
        int res = INT_MAX;
        for (int rot = 0; rot < 4; rot++) {
            int n = A.size(), m = A[0].size();
            for (int i = 1; i < n; i++) {
                // top part (rows 0..i-1)
                vector<vector<int>> part1(A.begin(), A.begin() + i);
                int a1 = minimumArea(part1);

                // split remaining rows horizontally
                for (int j = 1; j < m; j++) { // ensure non-empty splits
                    vector<vector<int>> part2(n - i, vector<int>(j));
                    vector<vector<int>> part3(n - i, vector<int>(m - j));
                    for (int r = 0; r < n - i; r++) {
                        copy(A[i + r].begin(), A[i + r].begin() + j, part2[r].begin());
                        copy(A[i + r].begin() + j, A[i + r].end(), part3[r].begin());
                    }
                    int a2 = minimumArea(part2);
                    int a3 = minimumArea(part3);
                    res = min(res, a1 + a2 + a3);
                }

                // split remaining rows vertically
                for (int i2 = i + 1; i2 < n; i2++) { // ensure part3 non-empty
                    vector<vector<int>> part2(A.begin() + i, A.begin() + i2);
                    vector<vector<int>> part3(A.begin() + i2, A.end());
                    int a2 = minimumArea(part2);
                    int a3 = minimumArea(part3);
                    res = min(res, a1 + a2 + a3);
                }
            }
            A = rotate(A); // rotate matrix for next orientation
        }
        return (res == INT_MAX ? 0 : res);
    }

private:
    // compute bounding box area of all 1s in matrix A
    int minimumArea(const vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int n = A.size(), m = A[0].size();
        int left = INT_MAX, top = INT_MAX, right = -1, bottom = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 1) {
                    left = min(left, j);
                    top = min(top, i);
                    right = max(right, j);
                    bottom = max(bottom, i);
                }
            }
        }
        if (right == -1) return 0; // no 1s
        return (right - left + 1) * (bottom - top + 1);
    }

    // rotate matrix 90 degrees clockwise
    vector<vector<int>> rotate(const vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> rotated(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[j][n - 1 - i] = A[i][j];
            }
        }
        return rotated;
    }
};