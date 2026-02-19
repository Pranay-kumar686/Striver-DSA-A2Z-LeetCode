class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int dup=x;
        long long rn=0;
        int ld=0;
        while(x!=0){
            ld = x % 10;
            x = x / 10;
            rn = (rn * 10) + ld;
        }
        if(rn == dup) return true;
        else return false;
    }
};