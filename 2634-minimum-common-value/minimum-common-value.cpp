class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int res=-1;
        int i=0, j=0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else{
                res = nums1[i];
                break;
            }
        }
        return res;
    }
};