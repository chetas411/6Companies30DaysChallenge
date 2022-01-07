class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int i = 0, j = 0;
        while(j < n){
            if(j - i + 1 < k){
                pq.push({arr[j],j});
                ++j;
            }
            else{
                pq.push({arr[j],j});
                ans.push_back(pq.top().first);
                while(!pq.empty() && pq.top().second <= i){
                    pq.pop();
                }
                ++i;
                ++j;
            }
        }
        return ans;
    }
};