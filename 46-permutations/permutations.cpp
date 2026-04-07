#include <vector>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans) {
        // Base case
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            // Swap
            swap(nums[index], nums[i]);

            // Recurse
            solve(index + 1, nums, ans);

            // Backtrack
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};