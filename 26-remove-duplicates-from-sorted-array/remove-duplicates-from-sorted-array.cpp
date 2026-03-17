class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        int slow=1;
        for(int fast=1; fast < k; fast++){
            if(nums[fast] != nums[slow-1]){
                nums[slow]=nums[fast];
                slow++; 
            }
        }
        return slow;
    }
};