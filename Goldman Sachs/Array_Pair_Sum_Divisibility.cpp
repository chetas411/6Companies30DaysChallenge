class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int> mp;
        for(auto x : nums){
            ++mp[x%k];
        }
        for(auto x : mp){
            if(x.first == 0 && x.second%2 != 0) return false;
            else if(x.first != 0 && mp[k-x.first] != x.second) return false;
        }
        return true;
    }
};