// here k = 10
vector<int> getMaxKNumbers(vector<int> nums, int k){
    priority_queue<int> maxheap;
    for(auto m : nums){
        maxheap.push(m);
    }
    vector<int> maxNums;
    while(k--){
        maxNums.push_back(maxheap.top());
        maxheap.pop();
    }
    return maxNums;
}
