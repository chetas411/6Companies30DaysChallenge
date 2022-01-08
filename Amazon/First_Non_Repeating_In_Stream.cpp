class Solution{
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> mp;
		    queue<char> q;
		    string ans = "";
		    for(int i=0;i<A.length();i++){
		        if(ans == ""){
		            q.push(A[i]);
		            ++mp[A[i]];
		            ans.push_back(A[i]);
		            continue;
		        }
		        ++mp[A[i]];
		        if(mp[A[i]] == 1) q.push(A[i]);
		        while(!q.empty()){
		            if(mp[q.front()] == 1){
		                break;
		            }
		            q.pop();
		        }
		        if(!q.empty()){
		            ans.push_back(q.front());
		        }
		        else{
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}
};