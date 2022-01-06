class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int currentMountain = 1, maxTillFar = 0;
        bool isIncreasing = (arr[0] < arr[1]), hasPeakArrived = false;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i] < arr[i+1]){
                if(isIncreasing){
                    ++currentMountain;
                }else{
                    if(hasPeakArrived){
                        maxTillFar = max(currentMountain,maxTillFar);
                        hasPeakArrived = false;
                    }
                    currentMountain = 2;
                    isIncreasing = true;
                }
            }
            else if(arr[i] > arr[i+1]){
                if(isIncreasing){
                    hasPeakArrived = true;
                    isIncreasing = false;
                }
                ++currentMountain;
            }
            else{
                if(hasPeakArrived){
                    maxTillFar = max(currentMountain,maxTillFar);
                    hasPeakArrived = false;
                }
                currentMountain = 1;
                if(i < arr.size()-2){
                    isIncreasing = (arr[i+1] < arr[i+2]);
                }
            }
        }
        if(hasPeakArrived){
            maxTillFar = max(maxTillFar,currentMountain);
        }
        return maxTillFar;
    }
};