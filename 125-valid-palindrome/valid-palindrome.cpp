class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char ch : s){
            if(isalnum(ch)){
                temp += tolower(ch);
            }
        }
        string rev=temp;
        reverse(rev.begin(), rev.end());
        if(rev == temp) return true;
        else return false;

    }
};