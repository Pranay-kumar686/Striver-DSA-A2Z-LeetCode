class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> st(s.begin(), s.end());
        
        for (char c = 'Z'; c >= 'A'; c--) {
            if (st.count(c) && st.count(c + 32))
                return string(1, c);
        }
        
        return "";
    }
};