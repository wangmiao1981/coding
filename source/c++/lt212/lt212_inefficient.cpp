class Solution {
public:

    void findUtil(vector<vector<char>>& board, unordered_map<string, int>& m, string out, int i, int j, vector<vector<bool>>& visited, vector<string>& res) {
        visited[i][j] = true;
        if (m.find(out + board[i][j]) != m.end()) {
            m[out+board[i][j]]++;
            if (m[out+board[i][j]] == 2)
            res.push_back(out + board[i][j]);
        }
        if (i - 1 >= 0 && !visited[i-1][j]) findUtil(board, m, out + board[i][j], i - 1, j, visited, res);
        if (i + 1 < board.size() && !visited[i+1][j])findUtil(board, m, out + board[i][j], i + 1, j, visited, res);
        if (j - 1 >= 0 && !visited[i][j-1])findUtil(board, m, out + board[i][j], i, j - 1, visited, res);
        if (j + 1 < board[0].size() && !visited[i][j+1]) {findUtil(board, m, out + board[i][j], i, j + 1, visited, res);}
        visited[i][j] = false;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++) {
            m[words[i]] = 1;
        }
        int row = board.size();
        int col = board[0].size();
        vector<string> res;
        if (row == 0 || col == 0) return res;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                vector<vector<bool>> visited(row, vector<bool>(col, false));
                findUtil(board, m, "", i, j, visited, res);
            }
        }
        
        return res;
    }
};
