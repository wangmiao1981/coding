class Solution {
public:

    bool util(vector<vector<char>>& board, int i, int j, int m, int n, string word, int pos, vector<vector<bool>>& visited) {
        if (i < 0 || i >= m || j < 0 || j >=n) return false;
        if (!visited[i][j] && pos == word.size() - 1 && word[pos] == board[i][j]) {
            return true;
        }
        if (!visited[i][j] && board[i][j] == word[pos]) {
            visited[i][j] = true;
            bool found = util(board, i - 1, j, m, n, word, pos+1, visited)
            || util(board, i + 1, j, m, n, word, pos+1, visited)
            || util(board, i, j - 1, m, n, word, pos+1, visited)
            || util(board, i, j + 1, m, n, word, pos+1, visited);
            visited[i][j] = false;
            return found;
        } else {
            return false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        if (board.size() == 0 || board[0].size() == 0) return false;
        int m = board.size();
        int n = board[0].size();
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    found = util(board, i, j, m, n, word, 0, visited);
                    if (found) return found;
                }
            }
        }
        return found;
    }
};
