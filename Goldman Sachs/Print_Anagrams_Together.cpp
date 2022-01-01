// First Solution with map
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string,vector<string>> mp;
        int n = string_list.size();
        for(int i=0;i<n;i++){
            string s = string_list[i];
            sort(s.begin(),s.end());
            mp[s].push_back(string_list[i]);
        }
        vector<vector<string>> ans;
        for(auto vec = mp.begin(); vec != mp.end(); vec++){
            ans.push_back(vec->second);
        }
        return ans;
    }
};

// Second Solution with sorting 
class Solution{
  public:
    static bool stringcomparison(const pair<string,int> &a, const pair<string,int> &b){
        if(a.first == b.first){
            return (a.second < b.second);
        }
        return (a.first < b.first);
    }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        vector<pair<string,int>> temp;
        for(int i=0;i<n;i++){
            string s = string_list[i];
            sort(s.begin(),s.end());
            temp.push_back({s,i});
        }
        sort(temp.begin(),temp.end(),stringcomparison);
        vector<vector<string>> ans;
        vector<string> curr;
        string last = "";
        for(auto p : temp){
            if(last == ""){
                curr.push_back(string_list[p.second]);
                last = p.first;
            }
            else if(last == p.first){
                curr.push_back(string_list[p.second]);
            }
            else{
                ans.push_back(curr);
                curr.clear();
                curr.push_back(string_list[p.second]);
                last = p.first;
            }
        }
        if(curr.size() != 0){
            ans.push_back(curr);
        }
        return ans;
    }
};