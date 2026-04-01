class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int cnt=0;
        int n = nums.size();
        for(int a=0; a<n; a++){
            for(int b = a+1; b < n; b++){
                for(int c=b+1; c < n; c++){
                    for(int d=c+1; d < n; d++){
                        if(nums[a] + nums[b] + nums[c] == nums[d]){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};