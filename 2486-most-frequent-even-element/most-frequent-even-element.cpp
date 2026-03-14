class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }
        int ans = -1;
        int maxFreq=0;
        for(auto &p : freq){
            if(p.first % 2 == 0){
                if(maxFreq < p.second){
                    ans=p.first;
                    maxFreq=p.second;
                }
                else if(maxFreq == p.second && p.first < ans){
                    ans=p.first;
                    maxFreq=p.second;
                }
            }
        }
        return ans;
    }
};