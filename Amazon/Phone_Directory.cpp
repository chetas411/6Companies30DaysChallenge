class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        sort(contact,contact+n);
        vector<vector<string>> ans;
        for(int i=1;i<=s.length();i++){
            string prefix = s.substr(0,i);
            vector<string> v;
            for(int j=0;j<n;j++){
                if(j > 0 && contact[j] == contact[j-1]) continue;
                string curr = contact[j];
                string currPrefix = curr.substr(0,i);
                if(currPrefix == prefix){
                    v.push_back(curr);
                }
            }
            if(v.size() == 0){
                string emp = "";
                emp.push_back('0');
                v.push_back(emp);
            }
            ans.push_back(v);
        }
        return ans;
    }
};