class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Traverse the first and last row for both oceans
        for (int i = 0; i < n; i++) {
            dfs(heights, 0, i, pacific, INT_MIN);      // Top row for Pacific
            dfs(heights, m - 1, i, atlantic, INT_MIN); // Bottom row for Atlantic
        }

        // Traverse the first and last column for both oceans
        for (int j = 0; j < m; j++) {
            dfs(heights, j, 0, pacific, INT_MIN);      // Left column for Pacific
            dfs(heights, j, n - 1, atlantic, INT_MIN); // Right column for Atlantic
        }

        // Collect coordinates that can flow to both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

private:
    // DFS function to mark reachable cells
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& ocean, int prev) {
        int m = heights.size();
        int n = heights[0].size();

        // Boundary conditions and value checks
        if (i < 0 || j < 0 || i >= m || j >= n || ocean[i][j] == 1 || heights[i][j] < prev)
            return;

        ocean[i][j] = 1; // Mark as visited

        // Recursive DFS calls for adjacent cells
        dfs(heights, i + 1, j, ocean, heights[i][j]);
        dfs(heights, i - 1, j, ocean, heights[i][j]);
        dfs(heights, i, j + 1, ocean, heights[i][j]);
        dfs(heights, i, j - 1, ocean, heights[i][j]);
    }
};
