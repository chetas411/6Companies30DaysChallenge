class Solution{
public:
    pair<string,int> getMinOperations(int p[], string s, int i, int j, vector<vector<pair<string,int>>> &dp){
        if(dp[i][j].second != -1) return dp[i][j];
        if( i == j){
            dp[i][j] = {s.substr(i,1),0};
            return dp[i][j];
        }
        int product = INT_MAX;
        string q = "";
        for(int k=i;k<j;k++){
            pair<string,int> x = getMinOperations(p,s,i,k,dp);
            pair<string,int> y = getMinOperations(p,s,k+1,j,dp);
            string r = "";
            r.push_back('(');
            r += x.first + y.first;
            r.push_back(')');
            if(x.second+y.second + p[i]*p[k+1]*p[j+1] < product){
                product = x.second+y.second + p[i]*p[k+1]*p[j+1];
                q = r;
            }
        }
        dp[i][j] = {q,product};
        return dp[i][j];
        
    }
    string matrixChainOrder(int p[], int n){
        // code here
        string s = "",r="";
        for(int i=0;i<n-1;i++){
            s.push_back(char('A' + i));
        }
        vector<vector<pair<string,int>>> dp(n-1,vector<pair<string,int>>(n-1));
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                dp[i][j] = {r,-1};
            }
        }
        pair<string,int> ans = getMinOperations(p,s,0,s.length()-1,dp);
        // cout<<ans.second<<endl;
        return ans.first;
        
    }
};