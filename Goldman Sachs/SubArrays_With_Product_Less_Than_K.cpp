// sliding window algorithm, if the we include the next element in the current product 
// and the product is still less than K then total subarrays now are (end - start + 1)
// but if the product gets greater than K then we need to shorten the window by moving
// start towards right and dividing the product by element at start and keep 
// looping this till we get the product again lesser than k
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int currProduct = 1, i = 0, j = 0, ans = 0;
        while(j < n){
            currProduct *= a[j];
            while(currProduct >= k && i <= j){
                currProduct /= a[i];
                ++i;
            }
            if(currProduct < k){
                ans += j - i + 1;
            }
            ++j;
        }
        return ans;
    }
};