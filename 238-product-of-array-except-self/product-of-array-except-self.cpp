class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);//(1,1,1,1)
        //divide the nums into left and right splits
        //left side product
        for(int i=1; i<n; i++){
            answer[i] = answer[i-1] * nums[i-1];
        }
        //right split product
        int right=1;
        for(int i=n-1; i>= 0; i--){
            answer[i] *= right;
            right *= nums[i];
        }
        return answer;
    }
};