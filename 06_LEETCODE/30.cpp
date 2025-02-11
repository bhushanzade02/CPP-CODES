class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            int r = matrix.size();       // Number of rows
            int c = matrix[0].size();    // Number of columns
    
            // Check each element with the one in the next row and next column
            for (int i = 0; i < r - 1; i++) {
                for (int j = 0; j < c - 1; j++) {
                    
                    if (matrix[i][j] != matrix[i + 1][j + 1]) {
                        return false;
                    }
                }
            }
            return true;
        }
    };
    