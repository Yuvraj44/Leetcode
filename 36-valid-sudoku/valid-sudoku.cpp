class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector <unordered_set <int>> sr(9);
        vector <unordered_set <int>> sc(9);
        vector <unordered_set <int>> sbx(9);
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                continue;

                if(sr[i].find(board[i][j])!=sr[i].end() || sc[j].find(board[i][j])!=sc[j].end() || sbx[(3*(i/3))+(j/3)].find(board[i][j]) != sbx[(3*(i/3))+(j/3)].end())
                return false;

                sr[i].insert(board[i][j]);
                sc[j].insert(board[i][j]);
                sbx[(3*(i/3))+(j/3)].insert(board[i][j]);
            }
        }
        return true;
    }
};