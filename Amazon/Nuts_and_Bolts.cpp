class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    vector<pair<char,int>> visited = {
	        {'!',0},{'#',0},{'$',0},{'%',0},{'&',0},{'*',0},{'@',0},{'^',0},{'~',0}
	    };
	    unordered_map<char,int> mp;
	    for(int i=0;i<9;i++){
	        mp[visited[i].first] = i;
	    }
	    for(int i=0;i<n;i++){
	        int idx = mp[nuts[i]];
	        visited[idx].second = 1;
	    }
	    int j = 0;
	    for(int i=0;i<9;i++){
	        if(visited[i].second == 1){
	           nuts[j] = visited[i].first;
	           bolts[j] = visited[i].first;
	           ++j;
	        }
	    }
	}
};