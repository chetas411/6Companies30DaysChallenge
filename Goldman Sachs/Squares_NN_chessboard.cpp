class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        //1*1 + 2*2 + ......+ n*n = (n*(n+1)*(2*n+1))/6
        return (N*(N+1)*(2*N+1))/6;
        
    }
};