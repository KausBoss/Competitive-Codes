class Solution {
public:
    int missingNumber(vector<int> nums) {
        int xr=0;
        for(int i=0; i<nums.size(); i++){
        	xr ^=nums[i];
        	xr ^=i;
        }
        xr ^=nums.size();
        return xr;
    }
};