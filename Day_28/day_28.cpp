class Solution {
private:
    int rows, cols;

public:
    int findMaxFish(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxFishes = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    maxFishes = max(maxFishes, dfs(i, j, grid));
                }
            }
        }
        return maxFishes;
    }

private:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        int fishCount = grid[r][c];  
        grid[r][c] = 0;              

        fishCount += dfs(r - 1, c, grid);
        fishCount += dfs(r, c + 1, grid);
        fishCount += dfs(r + 1, c, grid);
        fishCount += dfs(r, c - 1, grid);

        return fishCount;
    }
};