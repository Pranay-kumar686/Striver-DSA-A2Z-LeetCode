class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }
        vector<pair<int, int>> arr(freq.begin(),freq.end());
        
        sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b){
            if(a.second != b.second){
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        vector<int> result;
        for(int i=0; i < k; i++){
            result.push_back(arr[i].first);
        }
        return result;
    }
};