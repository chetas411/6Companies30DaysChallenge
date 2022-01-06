
// Solution 1: Just trying every combination of buying and selling, but eventually
// the sub problems will be repeating so at the same time memoizing the answers at a given
// index i and number of transactions left k, so that just returning the answer at that
// instance of i and k if for that instance the profit is already calculated
class Solution {
  public:
    int getMaxProfit(int A[],int N, int i, int k, vector<vector<int>> &maxProfits){
        if(i >= N || k == 0) return 0;
        if(maxProfits[i][k] != -1) return maxProfits[i][k];
        int maxIfIncluded = 0;
        for(int j=i+1;j<N;j++){
            if(A[j] > A[i]){
                maxIfIncluded = max((A[j] - A[i] + getMaxProfit(A,N,j+1,k-1,maxProfits)),maxIfIncluded);
            }
        }
        int ifNotIncluded = getMaxProfit(A,N,i+1,k,maxProfits);
        maxProfits[i][k] = max(maxIfIncluded,ifNotIncluded);
        return maxProfits[i][k];
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>> maxProfits(N,vector<int> (K+1,-1));
        return getMaxProfit(A,N,0,K,maxProfits);
    }
};