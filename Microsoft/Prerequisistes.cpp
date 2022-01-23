// Checking if the graph is Directed Acyclic by finding Topological sort
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
	    vector<int> indegree(N,0);
	    for(auto p : prerequisites){
	        adj[p.second].push_back(p.first);
	        ++indegree[p.first];
	    }
	    vector<bool> visited(N,false);
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i] == 0){
	            q.push(i);
	            visited[i] = true;
	        }
	    }
	    int count = 0;
	    while(!q.empty()){
	        int curr = q.front();
	        q.pop();
	        ++count;
	        for(auto x : adj[curr]){
	            if(visited[x]) continue;
	            --indegree[x];
	            if(indegree[x] == 0) {
	                q.push(x);
	                visited[x] = true;
	            }
	        }
	    }
	    if(count == N) return 1;
	    return 0;
	}
};