class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // Find top sum
        long long topSum = 0;
        int n = grid[0].size();
        for (int i = 0; i < n; i++) {
            topSum += grid[0][i];
        }

        long long bottomSum = 0;
        long long ans = LLONG_MAX;

        for (int p = 0; p < n; p++) {
            // Subtract the current top value
            topSum -= grid[0][p];

            // Calculate the answer as the minimum of the maximum sums
            ans = min(ans, max(topSum, bottomSum));

            // Add the current bottom value
            bottomSum += grid[1][p];
        }

        // Return the result
        return ans;
    }
};