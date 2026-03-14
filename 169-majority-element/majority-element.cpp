class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }
        for(auto &p : freq){
            if(p.second > n / 2){
                return p.first;
            }
        }
        return -1;
    }
};