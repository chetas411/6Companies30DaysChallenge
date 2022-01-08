
/* 
    As the order does not matter so we need to simply see in how many possible number
    steps you can reach the Nth stair and no. of steps changes when we increase 2's
    for e.g.
    N = 4
    when 0 2's = 1 1 1 1
    when 1 2's = 2 1 1
    when 2 2's = 2 2
    so basically how many times 2 can be subtracted from N + 1 ( for the case when no 2 is there)
*/
class Solution{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int m)
    {
        // your code here
        return (m / 2) + 1;
    }
};