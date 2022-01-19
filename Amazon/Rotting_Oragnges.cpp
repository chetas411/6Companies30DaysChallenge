class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int emp = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j] = true;
                }
                if(grid[i][j] == 0){
                    ++emp;
                }
            }
        }
        vector<pair<int,int>> move = {{-1,0},{0,1},{1,0},{0,-1}};
        int currSize = q.size();
        int count = 0;
        int qty = m*n - emp;
        if(qty == 0) return 0; // when empty matrix

        // BFS
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            --currSize;
            --qty;
            for(int i=0;i<4;i++){
                int x = curr.first + move[i].first, y = curr.second + move[i].second;
                if(x >= 0 && x < m && y >= 0 && y < n){
                    if(!grid[x][y] || visited[x][y]){
                        continue;
                    }
                    grid[x][y] = 2;
                    q.push({x,y});
                    visited[x][y] = true;
                }
            }
            if(currSize == 0){
                currSize = q.size();
                ++count;
            }
        }
        if(qty == 0) return count-1;
        return -1;
        
    }
};