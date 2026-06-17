class Solution {
public:
    char processStr(string s, long long k) {
          int n = s.size();
        vector<long long> len(n + 1, 0);
        const long long LIM = (long long)1e15;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                len[i + 1] = min(LIM, len[i] + 1);
            } 
            else if (c == '*') {
                len[i + 1] = (len[i] ? len[i] - 1 : 0);
            } 
            else if (c == '#') {
                len[i + 1] = min(LIM, len[i] * 2);
            } 
            else { // '%'
                len[i + 1] = len[i];
            }
        }
        if (k >= len[n]) return '.';
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                if (k == len[i])
                    return c;
            }
            else if (c == '*') {
                if (k == len[i]) {
                }
            }
            else if (c == '#') {
                if (k >= len[i])
                    k -= len[i];
            }
            else { 
                k = len[i] - 1 - k;
            }
        }
        return '.';
    }
};