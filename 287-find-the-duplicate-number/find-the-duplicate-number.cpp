class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        int temp=0;
        for(int x : nums){
            if(st.count(x)){
                temp = x;
            }
            st.insert(x);
        }
        return temp;
    }
};