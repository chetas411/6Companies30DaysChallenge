class Solution {
    public:
    //Function to find unit area of the largest region of 1s.
    vector<pair<int,int>> v = {
        {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}
    };
    int getArea(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        visited[i][j] = true;
        int area = 1;
        for(auto x : v){
            int u = i+x.first, w = j+x.second;
            if(u < 0 || u >= grid.size() || w <0 || w  >= grid[0].size() || visited[u][w] || grid[u][w] == 0) continue;
            area += getArea(u,w,grid,visited);
        }
        return area;
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int area = getArea(i,j,grid,visited);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};