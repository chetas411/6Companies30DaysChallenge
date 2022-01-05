class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int dup = -1;
        for(int i=0;i<n;i++){
            int k = abs(arr[i]) - 1;
            if(arr[k] < 0){
                dup = k+1;
            }
            else{
                arr[k] *= -1;   
            }
        }
        int* ans = new int(2);
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                ans[0] = dup;
                ans[1] = i+1;
                return ans;
            }
        }
    }
};