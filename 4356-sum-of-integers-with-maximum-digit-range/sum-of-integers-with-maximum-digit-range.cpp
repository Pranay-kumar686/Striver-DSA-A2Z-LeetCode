class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRnge=-1;
        int resss=0;
        for(int num : nums){
            int x=num;
            //123467890-asdfghjk
            int smlst=9;
            int lrgst=0;
            while(x>0){
                int dgt=x%10;
                smlst=min(smlst, dgt);
                lrgst=max(lrgst, dgt);
                x/=10;
            }
            //zxcvbnm
            int range=lrgst-smlst;
            if(range>maxRnge){
                maxRnge=range;
                resss=num;
            }else if(range==maxRnge){
                resss+=num;
            }
        }
        return resss;
    }
};