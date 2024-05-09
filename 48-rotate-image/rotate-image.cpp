class Solution {
public:

    void transpose(vector <vector <int>> & matrix)
    {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=i+1; j<matrix.size(); j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    void rev(vector<vector<int>>& matrix)
    {
        for(int i=0; i<matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        rev(matrix);
    }
};