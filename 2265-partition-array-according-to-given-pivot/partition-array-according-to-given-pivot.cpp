class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
         vector<int> ls, eql, grtr;
         //DAY-07
        for (int num : nums) {
            if (num < pivot) {
                ls.push_back(num);
            } else if (num == pivot) {
                eql.push_back(num);
            } else {
                grtr.push_back(num);
            }
        }
        //sdfgertyuiop
        vector<int> ans;
        ans.reserve(nums.size());
        for (int num : ls) ans.push_back(num);
        for (int num : eql) ans.push_back(num);
        for (int num : grtr) ans.push_back(num);
        return ans;
    }
};