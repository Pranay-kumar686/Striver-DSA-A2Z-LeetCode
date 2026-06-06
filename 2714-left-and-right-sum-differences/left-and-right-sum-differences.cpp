class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int total = 0;
         for (int x : nums) {
            total += x;
        }
        vector<int> ans;
        int leftSum = 0;
        for (int x : nums) {
            total -= x;  
            ans.push_back(abs(leftSum - total));
            leftSum += x;
        }
        return ans;
    }
};