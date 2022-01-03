// Solution 1: Brute force solution will check every number till we get nth ugly number,
// this will give TLE
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    int count = 1;
	    ull num = 2;
	    while(count < n){
	        ull curr = num;
	        while(curr != 1 && curr%2 == 0){
	            curr /= 2;
	        }
	        while(curr != 1 && curr%3 == 0){
	            curr /= 3;
	        }
	        while(curr != 1 && curr%5 == 0){
	            curr /= 5;
	        }
	        if(curr == 1){
	            ++count;
	        }
	        ++num;
	    }
	    return num - 1;
	}
};

// Solution 2: Dynamic Programming
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    vector<ull> nums;
	    nums.push_back(1);
	    ull m2 = 0, m3 = 0, m5 = 0, n2 = 0, n3 = 0, n5 = 0;
	    while(nums.size() < n){
	        m2 = nums[n2]*2;
	        m3 = nums[n3]*3;
	        m5 = nums[n5]*5;
	        ull curr = min(m2,min(m3,m5));
	        nums.push_back(curr);
	        if(curr == m2) ++n2;
	        if(curr == m3) ++n3;
	        if(curr == m5) ++n5;
	    }
	    return nums[n-1];
	}
};