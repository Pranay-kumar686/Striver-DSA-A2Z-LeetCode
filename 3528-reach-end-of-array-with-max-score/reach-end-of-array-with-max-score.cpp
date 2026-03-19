class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n =nums.size();
        long long ans=0;
        int maxSoFar = nums[0];
        for(int i=1; i<n; i++){
            ans += maxSoFar;
            maxSoFar = max(maxSoFar, nums[i]);
        }
        return ans;
    }
};