class Solution {
public:
    string toLowerCase(string s) {
        for(char &c : s)
        //123456
            c = tolower(c);
        return s;
    }
};