class Solution {
    public:
    //Function to find the maximum money the thief can get.
    
    int FindMaxSum(int arr[], int n){
        // Your code here
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0],arr[1]);
        vector<int> include(n,0);
        vector<int> exclude(n,0);
        for(int i=0;i<n;i++){
            if(i == 0){
                include[i] = arr[0];
                continue;
            }
            exclude[i] = max(include[i-1],exclude[i-1]);
            include[i] = exclude[i-1] + arr[i]; 
        }
        return max(include[n-1],exclude[n-1]);
    }
};