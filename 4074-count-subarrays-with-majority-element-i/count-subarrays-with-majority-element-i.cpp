class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) arr[i] = 1;
            else arr[i] = -1;
        }        
        int prefix = 0;
        long long count = 0;        
        multiset<int> st;
        st.insert(0);          
        for (int i = 0; i < n; i++) {
            prefix += arr[i];            
            count += distance(st.begin(), st.lower_bound(prefix));            
            st.insert(prefix);
        }        
        return count;
    }
};