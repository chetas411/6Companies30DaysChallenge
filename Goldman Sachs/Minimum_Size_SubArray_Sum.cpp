class Solution {
public:
    // Sliding window approach
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, currSum = 0, minLen = INT_MAX;
        while(j < nums.size()){
            currSum += nums[j];
            while(currSum >= target){
                minLen = min(minLen, j-i+1);
                currSum -= nums[i];
                ++i;
            }
            ++j;
        }
        return (minLen == INT_MAX)? 0 : minLen;
    }
};