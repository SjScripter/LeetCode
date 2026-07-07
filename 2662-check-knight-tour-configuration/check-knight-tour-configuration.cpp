class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
      
        int n = grid.size();
        vector<pair<int, int>> positions(n * n);
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                int moveNumber = grid[row][col];
                positions[moveNumber] = {row, col};
            }
        }
      
        for (int moveNum = 1; moveNum < n * n; ++moveNum) {
            auto [prevRow, prevCol] = positions[moveNum - 1];
            auto [currRow, currCol] = positions[moveNum];
            int rowDiff = abs(prevRow - currRow);
            int colDiff = abs(prevCol - currCol);
            bool isValidKnightMove = (rowDiff == 1 && colDiff == 2) || 
                                     (rowDiff == 2 && colDiff == 1);
          
            if (!isValidKnightMove) {
                return false;
            }
        }
      
        return true;
    }
};
