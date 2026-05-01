class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 3) return -1;

        int a = nums[0], b = nums[1], c = nums[2];

        if((a > b && a < c) || (a < b && a > c)) return a;
        if((b > a && b < c) || (b < a && b > c)) return b;
        return c;
    }
};