class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxRch=0;
        for(int i=0; i<n; i++){
            if(i > mxRch) return false;
            mxRch = max(mxRch, i+nums[i]);
        }
        return true;
    }
};