class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  // Possible directions: down, up, right, left

    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx, int m, int n) {
        // If the index reaches the word's length, it means we've found the word
        if (idx == word.size()) return true;
        
        // Check for boundaries, visited cell, or if the current cell does not match the word character
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' || board[i][j] != word[idx])
            return false;
        
        // Mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all 4 directions
        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (find(board, new_i, new_j, word, idx + 1, m, n)) {
                return true;
            }
        }
        
        // Backtrack: restore the original character in the board
        board[i][j] = temp;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();    // Number of rows
        int n = board[0].size(); // Number of columns

        // Loop through the board to find the starting point of the word
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the first character matches, start the recursive search
                if (board[i][j] == word[0] && find(board, i, j, word, 0, m, n)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
