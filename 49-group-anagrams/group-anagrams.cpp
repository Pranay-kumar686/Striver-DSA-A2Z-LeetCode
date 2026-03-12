class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // creates a empty map with key and result fields
        for(string s : strs){ // loop through given i/o strs
            string key = s;//assign 1st string in strs as key
            sort(key.begin(), key.end());//sort the key s i.e 1st word 
            mp[key].push_back(s);//push that to the map[key] postion / field
        }
        vector<vector<string>> result;//empty container for storing sorted strings 
        for(auto &it : mp){ // loop thorugh the mp
            result.push_back(it.second); // stores only the values i.e the sorted values into the result
        }
        return result;
    }
};