class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> seen;
        if(n==1) return false;
        for(int num : nums){
            if(seen.count(num) >0){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};