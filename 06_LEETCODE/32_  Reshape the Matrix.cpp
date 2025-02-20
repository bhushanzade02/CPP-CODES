class Solution
{
public:
    vector<vector<int>>
    matrixReshape(vector<vector<int>> &mat, int r, int c)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        if (m * n != r * c)
        {
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c, 0));
        int a = 0;
        int b = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[a][b] = mat[i][j];
                b++;
                if (b == c)
                {
                    a++;
                    b = 0;
                }
            }
        }
        return ans;
    }
};