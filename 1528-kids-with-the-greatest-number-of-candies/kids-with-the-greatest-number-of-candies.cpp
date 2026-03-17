class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for(int i=0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maxCandy){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};