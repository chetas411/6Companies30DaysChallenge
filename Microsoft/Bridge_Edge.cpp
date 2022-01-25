class Solution {
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int u, vector<int> adj[], vector<bool> &visited){
        if(visited[u]) return;
        visited[u] = true;
        for(auto v : adj[u]){
            if(visited[v]) continue;
            dfs(v,adj,visited);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) {
        // Code here
        vector<vector<int>> graph(V);
        vector<bool> visited(V,false);
        vector<int> C, D;
        for(int i=0;i<adj[c].size();i++){
            if(adj[c][i] != d){
                C.push_back(adj[c][i]);
            }
        }
        for(int i=0;i<adj[d].size();i++){
            if(adj[d][i] != c){
                D.push_back(adj[d][i]);
            }
        }
        adj[c] = C;
        adj[d] = D;
        dfs(c,adj,visited);
        return (visited[d] == false);
    }
};