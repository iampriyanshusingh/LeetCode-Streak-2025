class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Initialize the adjacency matrix
        vector<vector<bool>> mat(numCourses, vector<bool>(numCourses, false));
        
        // Populate the adjacency matrix with prerequisites
        for (const auto& pre : prerequisites) {
            int s = pre[0];
            int d = pre[1];
            mat[s][d] = true;
        }

        // Use Floyd-Warshall algorithm to find transitive closure
        for (int k = 0; k < numCourses; k++) {
            for (int s = 0; s < numCourses; s++) {
                for (int d = 0; d < numCourses; d++) {
                    mat[s][d] = mat[s][d] || (mat[s][k] && mat[k][d]);
                }
            }
        }

        // Process queries
        vector<bool> ans;
        for (const auto& query : queries) {
            int s = query[0];
            int d = query[1];
            ans.push_back(mat[s][d]);
        }

        return ans;
    }
};
