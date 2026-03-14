class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }
        int maxFreq=0;
        int ans = -1;
        for(auto &p : freq){
            if(p.first % 2 == 0){
                if(p.second > maxFreq){
                    maxFreq=p.second;
                    ans=p.first;
                }
                else if(maxFreq == p.second && p.first < ans){
                    maxFreq=p.second;
                    ans=p.first;
                }
            }
        }
        return ans;
    }
};