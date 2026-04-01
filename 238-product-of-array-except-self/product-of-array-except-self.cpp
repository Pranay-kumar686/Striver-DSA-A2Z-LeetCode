class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);//creates a vector of size n with all the values = 1 (1,1,1,1)
        // left side
        for(int i=1; i<n; i++){
            res[i] = res[i-1] * nums[i-1];
        }
        //right product
        int right=1;
        for(int i=n-1; i>=0; i--){
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};