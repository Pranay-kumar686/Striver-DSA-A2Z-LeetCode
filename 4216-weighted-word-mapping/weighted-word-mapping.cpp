class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto &s : words){
            int sum = 0;
            for(char ch : s) sum += weights[ch - 'a'];
                ans += char('z' - (sum % 26));
        }
        return ans;
    }
};