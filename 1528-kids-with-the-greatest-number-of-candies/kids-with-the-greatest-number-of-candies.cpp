class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        for(int i=0; i<candies.size(); i++){
            int currCan=candies[i]+extraCandies;
            bool greatest = true;
            for(int j=0; j<candies.size(); j++){
                if(currCan < candies[j]){
                    greatest=false;
                    break;
                }
            }
            res.push_back(greatest);
        }
        return res;
    }
};