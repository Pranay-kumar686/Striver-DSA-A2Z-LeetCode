class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int c = 1;
        
        while (s.size() < b.size()) {
            s += a;
            c++;
        }
        
        if (s.find(b) != string::npos) return c;
        
        s += a;
        return s.find(b) != string::npos ? c + 1 : -1;
    }
};