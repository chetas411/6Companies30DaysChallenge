class Solution {
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c){
        // code here
        int k = 0;
        vector<int> ans;
        for(int i=0;i<r && k < c;){
            for(int j=k;j<c;j++) ans.push_back(matrix[i][j]);
            i++;
            for(int j=i;j<r;j++) ans.push_back(matrix[j][c-1]);
            --c;
            if(i < r){
                for(int j=c-1;j>=k;j--) ans.push_back(matrix[r-1][j]);
                --r;   
            }
            if(k < c){
                for(int j=r-1;j>=i;j--) ans.push_back(matrix[j][k]);
                ++k;   
            }
            
        }
        return ans;
    }
};