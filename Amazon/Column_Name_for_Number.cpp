class Solution{
    public:
    string colName (long long int n){
        // your code here
        string col = "";
        while(n){
            --n;
            int rem = n%26;
            col.push_back(char('A'+rem));
            n = n/26;
        }
        reverse(col.begin(),col.end());
        return col;
    }
};