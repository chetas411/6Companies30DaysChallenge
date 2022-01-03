class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        if(N == 1) return 1;
        int diff = M%N + K-1;
        if(diff == N) return N;
        return diff%N;
    }
};