class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        //aopihtreevh
        return ((start[0]+ start[1]) & 1) == ((target[0] + target[1]) & 1);
    }
};