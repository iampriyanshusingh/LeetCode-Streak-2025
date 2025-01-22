class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // Directions: up, right, down, left
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1)); // Result matrix initialized to -1
        queue<pair<int, int>> q; // Queue to process cells

        // Initialize the queue with water cells and set their height to 0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // BFS to calculate heights
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int h = res[r][c]; // Current height
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                
                // Check if the neighbor cell is within bounds and unvisited
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && res[nr][nc] == -1) {
                    res[nr][nc] = h + 1; // Set height and mark as visited
                    q.push({nr, nc});
                }
            }
        }

        return res;
    }
};