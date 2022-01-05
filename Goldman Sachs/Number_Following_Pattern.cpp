class Solution{
public:
    string printMinNumberForPattern(string S){
        // code here 
        vector<pair<char,int>> arr;
        char p = S[0];
        int count = 1;
        for(int i=1;i<S.length();i++){
            if(S[i] != p){
                arr.push_back({p,count});
                p = S[i];
                count = 1;
                continue;
            }
            ++count;
        }
        arr.push_back({p,count});
        int num = 1;
        int curr = 1;
        for(int i=0;i<arr.size();i++){
            char c = arr[i].first;
            int x = arr[i].second;
            if(c == 'I'){
                if(i == arr.size()-1 && i == 0) ++x;
                else if(i != 0 && i!=arr.size() - 1) --x;
                while(x--){
                    num = num*10 + curr;
                    ++curr;
                }
            }
            else{
                int y = curr + x;
                while(y >= curr){
                    num = num*10+y;
                    --y;
                }
                curr += (x+1);
            }
        }
        return to_string(num).substr(1);
    }
};