class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int r = grid.size();
        int c = grid[0].size();
        int s = r*c;

        k = k%s;

        vector<vector<int>> ans(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                int ni = i*c+j+k;
                int nr = (ni/c)%r;
                int nc = ni%c;

                ans[nr][nc] = grid[i][j];
            }
        }
        return ans;
        
    }
};