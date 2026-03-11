class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }
        vector<pair<int, int>> arr;
        for(auto &p : freq){
            arr.push_back(p);
        }
        sort(arr.begin(), arr.end(), [](pair<char, int> a, pair<char, int> b){
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