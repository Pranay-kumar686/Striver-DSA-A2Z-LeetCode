class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        for(auto &p : freq){
            if(p.second > n /2){
                res=p.first;
            }
        }
        return res;
    }
};