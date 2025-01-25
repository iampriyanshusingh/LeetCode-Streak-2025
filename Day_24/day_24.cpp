class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> visited; // Similar to Java's HashMap
        int n = graph.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, visited)) {
                result.push_back(i);
            }
        }
        return result;
    }

private:
    bool dfs(int node, vector<vector<int>>& graph, unordered_map<int, bool>& visited) {
        // If the node has been visited, return its state
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        visited[node] = false; // Mark as visited (in the current path)
        for (int neighbour : graph[node]) {
            if (!dfs(neighbour, graph, visited)) {
                return false; // If any neighbor is not safe, the node is not safe
            }
        }

        visited[node] = true; // Mark as safe
        return true;
    }
};