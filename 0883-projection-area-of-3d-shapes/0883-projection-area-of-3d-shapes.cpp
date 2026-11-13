class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {

        int n = grid.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int rowMax = 0;
            int colMax = 0;

            for(int j = 0; j < n; j++)
            {
                // Top projection
                if(grid[i][j] > 0)
                {
                    ans++;
                }

                // Front projection
                rowMax = max(rowMax, grid[i][j]);

                // Side projection
                colMax = max(colMax, grid[j][i]);
            }

            ans += rowMax;
            ans += colMax;
        }

        return ans;
    }
};