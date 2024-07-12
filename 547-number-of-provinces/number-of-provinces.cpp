class Solution {
private:
    // DFS traversal function
    void dfs(int node, vector<int> adjLs[], vector<int>& vis) {
        // Mark the node as visited
        vis[node] = 1;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n]; // Use n to accommodate 0-based indexing

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Self nodes are not considered
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); // No adjustment needed for 0-based indexing
                    adjLs[j].push_back(i); // No adjustment needed for 0-based indexing
                }
            }
        }

        vector<int> vis(n, 0); // Use n to accommodate 0-based indexing
        int cnt = 0;
        for (int i = 0; i < n; ++i) { // Start from 0 for 0-based indexing
            // If the node is not visited
            if (!vis[i]) {
                // Counter to count the number of provinces
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};
