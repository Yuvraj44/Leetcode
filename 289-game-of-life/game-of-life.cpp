class Solution {
public:

    void func(vector<vector<int>>& board, int i, int j, int &live)
    {
        vector <int> dx={0, 1, 1, 1 , 0, -1, -1 ,-1};
        vector <int> dy={1, 1, 0, -1, -1, -1, 0, 1};

        for(int itr=0; itr<8; itr++)
        {
            int x=i+dx[itr];
            int y=j+dy[itr];

            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
            {
                if(abs(board[x][y])==1)
                live++;  
            }
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                int live=0;
                func(board, i, j, live);

                if (board[i][j] == 1 && (live < 2 || live > 3))//they die
                    board[i][j] = -1; 
                
                if (board[i][j] == 0 && live == 3)//they live
                    board[i][j] = 2;
            }
        }

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]==-1)
                board[i][j]=0;
                else if(board[i][j]==2)
                board[i][j]=1;
            }
        }

    }
};
