// Solution 1: Recursive
// This will give TLE as Time Complexity is about exponential
class Solution {
	public:
	    const int MOD = 1000000007;
	    int getMessages(string s){
            if (s == "" || s[0] == '0') return 0;
	        if(s.length() == 1) return 1;
	        int count1 = 0, count2 = 0;
	        count1 = getMessages(s.substr(1));
	        if(s.length() > 2 && stoi(s.substr(0,2)) <= 26){
	            count2 = getMessages(s.substr(2));
	        }
	        else if(s.length() == 2 && stoi(s) <= 26){
	            count2 = 1;
	        }
	        return (count1+count2)%MOD;
	        
	    }
		int CountWays(string str){
		    return getMessages(str);
		}
};


// Solution 2: Dynamic Programming
class Solution {
	public:
	    const int MOD = 1000000007;
		int CountWays(string str){
		    // Code here
		    int n = str.length();
		    vector<int> dp(n+1,0);
		    if(str[0] == '0') return 0;
		    // SubProblem: dp[i] indicates the count when the current string has 'i' characters
		    dp[0] = 1; // when string is empty
		    dp[1] = 1;
		    for(int i=2;i<=n;i++){
		        int j = i-1;
		        if(str[j] == '0'){
		            if(str[j-1] == '0') return 0;
		            int sub = stoi(str.substr(j-1,2));
		            if(sub <= 26) dp[i] += dp[i-2]%MOD;
		            if(sub > 26) return 0;
		        }
		        else{
		            dp[i] += dp[i-1]%MOD;
		            if(str[j-1] != '0' && stoi(str.substr(j-1,2)) <= 26){
		                dp[i] += dp[i-2]%MOD;
		            }
		        }
		        dp[i] = dp[i]%MOD;
		    }
		    return dp[n];
		}
};